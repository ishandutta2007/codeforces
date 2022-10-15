#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, f[N];
char str[N];

bool check(int k) {
    int x = 0, y = k;
    for (int i = 0; i < n; i++) {
        if (y <= str[i] - '0') {
            y = str[i] - '0'; f[i] = 2;
        } else if (x <= str[i] - '0') {
            x = str[i] - '0'; f[i] = 1;
            if (x > k) { return false; }
        } else {
            return false;
        }
    } return true;
}
bool check() {
    for (int i = 0; i <= 9; i++) {
        if (check(i)) { return true; }
    } return false;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); scanf("%s", str);
        if (check()) {
            for (int i = 0; i < n; i++) { putchar(f[i] + '0'); }
            printf("\n");
        } else {
            printf("-\n");
        }
    }
    return 0;
} //