#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int r = n % 4;
    if (r == 2 || r == 3) {
        puts("NO");
        return 0;
    }
    puts("YES");
    int k = n / 4;
    if (!r) {
        for (int i = 0; i < 2 * k; i ++)
        for (int j = i + 1; j < 2 * k; j ++) {
            printf("%d %d\n", 2 * i + 1, 2 * j + 1);
            printf("%d %d\n", 2 * i + 2, 2 * j + 2);
            printf("%d %d\n", 2 * i + 2, 2 * j + 1);
            printf("%d %d\n", 2 * i + 1, 2 * j + 2);
        }
        for (int i = 0; i < 2 * k; i ++) {
            printf("%d %d\n", 2 * i + 1, 2 * i + 2);
        }
    }
    else {
        for (int i = 0; i < 2 * k; i ++)
        for (int j = i + 1; j < 2 * k; j ++) {
            printf("%d %d\n", 2 * i + 1, 2 * j + 1);
            printf("%d %d\n", 2 * i + 2, 2 * j + 2);
            printf("%d %d\n", 2 * i + 2, 2 * j + 1);
            printf("%d %d\n", 2 * i + 1, 2 * j + 2);
        }
        for (int i = 0; i < 2 * k; i ++) {
            printf("%d %d\n", 2 * i + 1, n);
            printf("%d %d\n", 2 * i + 1, 2 * i + 2);
            printf("%d %d\n", 2 * i + 2, n);
        }
    }
}