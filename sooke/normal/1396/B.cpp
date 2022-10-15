#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 105;

int n, max, sum, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        max = 0; sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            sum += a[i];
            max = std::max(max, a[i]);
        }
        if (max * 2 <= sum) {
            printf("%s\n", sum % 2 == 0 ? "HL" : "T");
        } else {
            printf("T\n");
        }
    }
    return 0;
}