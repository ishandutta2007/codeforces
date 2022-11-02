#include<bits/stdc++.h>
using namespace std;

int n = 0;

void f(int x1, int y1, int x2, int y2)
{
    int x = x2 - x1;
    int y = y2 - y1;
    if(x == 0 && y == 0) return ;
    if(x > 0 && y > 0) {
        printf("RU\n");
        f(x1 + 1, y1 + 1, x2, y2);
    }
    if(x > 0 && y < 0) {
        printf("RD\n");
        f(x1 + 1, y1 - 1, x2, y2);
    }
    if(x < 0 && y > 0) {
        printf("LU\n");
        f(x1 - 1, y1 + 1, x2, y2);
    }
    if(x < 0 && y < 0) {
        printf("LD\n");
        f(x1 - 1, y1 - 1, x2, y2);
    }
    if(x == 0) {
        if(y > 0) {
            printf("U\n");
            f(x1, y1 + 1, x2, y2);
        }
        if(y < 0) {
            printf("D\n");
            f(x1, y1 - 1, x2, y2);
        }
    }
    if(y == 0) {
        if(x > 0) {
            printf("R\n");
            f(x1 + 1, y1, x2, y2);
        }
        if(x < 0) {
            printf("L\n");
            f(x1 - 1, y1, x2, y2);
        }
    }
}

int main()
{
    char s[10], t[10];
    scanf("%s%s", s, t);
    int x1 = s[0] - 'a';
    int y1 = s[1] - '1';
    int x2 = t[0] - 'a';
    int y2 = t[1] - '1';
    int x = abs(x2 - x1);
    int y = abs(y2 - y1);
    printf("%d\n", max(x, y));
    f(x1, y1, x2, y2);
    return 0;
}