#include <bits/stdc++.h>
using namespace std;

#define N 100100

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        if (n < 10) {
            printf("133");
            for (int i = 0; i < n; i ++) putchar('7');
            puts(""); continue;
        }
        int m = sqrt(2 * n);
        while (1ll * m * (m + 1) / 2 < n) m ++; m --;
        int x = m - 1, y = n - (1ll * m * (m + 1) / 2);
        printf("133");
        for (int i = 0; i < y; i ++) putchar('7');
        for (int i = 0; i < x; i ++) putchar('3');
        puts("7");
    }
}