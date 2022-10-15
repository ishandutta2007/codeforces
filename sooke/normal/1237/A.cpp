#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n;
bool flag;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        int x = read();
        if (x % 2 == 0) {
            printf("%d\n", x / 2);
        } else {
            flag ^= 1;
            if (flag) {
                printf("%d\n", (x + 100000) / 2 - 50000);
            } else {
                printf("%d\n", (x + 100000) / 2 - 49999);
            }
        }
    }    
    return 0;
}