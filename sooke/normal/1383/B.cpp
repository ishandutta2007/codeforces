#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, a[N];

bool check(int sum) {
    for (int u = 30; u >= 0; u--) {
        if (sum >> u & 1) {
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] >> u & 1) {
                    x++;
                } else {
                    y++;
                }
            }
            if (y % 2 == 0) {
                return x / 2 % 2 == 0;
            } else {
                return true;
            }
        }
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            sum ^= a[i];
        }
        if (sum == 0) { printf("DRAW\n"); continue; }
        printf("%s\n", check(sum) ? "WIN" : "LOSE");
    }
    return 0;
}