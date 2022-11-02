#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; i ++) scanf("%d", a + i);
    int x = (1 + sqrt(8ll * a[0] + 1)) / 2;
    if(x * (x - 1) != 2 * a[0]) {
        puts("Impossible");
        return 0;
    }
    int y = (1 + sqrt(8ll * a[3] + 1)) / 2;
    if(y * (y - 1) != 2 * a[3]) {
        puts("Impossible");
        return 0;
    }
    if(x == 1 && y == 1) {
        if(a[1] + a[2] > 1) puts("Impossible");
        else if(a[1] + a[2] == 0) puts("0");
        else if(a[1] == 1)puts("01");
        else puts("10");
        return 0;
    }
    if(x == 1) {
        if(a[1] + a[2] == 0) {
            for(int i = 0; i < y; i ++) putchar('1');
            return 0;
        }
    }
    if(y == 1) {
        if(a[1] + a[2] == 0) {
            for(int i = 0; i < x; i ++) putchar('0');
            return 0;
        }
    }
    if(a[1] + a[2] != x * y) {
        puts("Impossible");
        return 0;
    }
    int n = a[2] / x, r = a[2] % x;
    for(int i = 0; i < n; i ++) putchar('1');
    for(int i = 0; i < x - r; i ++) putchar('0');
    if(n == y) return 0;
    putchar('1');
    for(int i = 0; i < r; i ++) putchar('0');
    for(int i = 0; i < y - n - 1; i ++) putchar('1');
}