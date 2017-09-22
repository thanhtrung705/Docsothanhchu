#include <stdio.h>
#include <string.h>

char s[100];// Khai báo biến toàn cục để đọc ra giá trị khi gọi hàm trong hàm main
char *bachuso(unsigned int n) {// khai báo hàm đọc 3 chữ số
    //trả lại về giá trị địa chỉ đẩu tiên của chuỗi đế tránh lặp lại khi gọi hàm lần sau.
    s[0] = 0;// cần phải lưu ý nếu ko sẽ lặp lại liên tục!!!!!!!!!!!!!!!
    char docchu[10][5] = {" ", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    int donvi, chuc, tram;
    donvi = n % 10;
    n = n / 10;
    chuc = n % 10;
    tram = n / 10;
    if (tram > 0) {
        strcat(s, docchu[tram]);
        strcat(s, " tram ");
    }
    if (chuc > 0) {
        if (chuc == 1) {
            strcat(s, " muoi` ");
        } else {
            strcat(s, docchu[chuc]);
            strcat(s, " muoi ");
        }
    }

    if (chuc == 0 && tram != 0 && donvi == 5)// đọc giá trị năm khi hàng chục=0 và hàng trăm khác 0
        strcat(s, "le nam");
    if (donvi == 5 && chuc != 0 && tram != 0)
        strcat(s, " lam");
    if (chuc != 0 && tram == 0 && donvi != 5)// đọc số hàng đơn vị khi don vi khac 5 và hàng chục=0, hàng trăm khác 0
        strcat(s, docchu[donvi]);
    if (chuc == 0 && tram == 0 && donvi > 0)
        strcat(s, docchu[donvi]);
    return s;//trả về chuỗi cần đọc sau mỗi lần gọi
}

int main() {
    unsigned long a;
    unsigned int trieu, nghin, ty, donvi;
    printf("So can nhap la: ");
    scanf("%d", &a);
    if (a == 0)
        printf("khong");
    else {
        donvi = a % 1000;
        a = a / 1000;
        nghin = a % 1000;
        a = a / 1000;
        trieu = a % 1000;
        ty = a / 1000;
        if (ty > 0) {
            printf("%s ty ", bachuso(ty));
        }
        if (trieu > 0) {
            printf("%s trieu ", bachuso(trieu));
        }
        if (nghin > 0) {
            printf("%s nghin ", bachuso(nghin));
        }
        if (donvi > 0) {
            printf("%s", bachuso(donvi));
        }
    }
    return 1;
}

