#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], b[N], c[N];

int main() {
    for (int T = read(); T; T--) {
		n = read();
        for (int i = 1; i <= n; i++) { a[i] = read(); }
        for (int i = 1; i <= n; i++) { b[i] = read(); }
        for (int i = 1; i <= n; i++) { c[i] = read(); }
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                std::swap(a[i], b[i]);
            }
            if (i == n) {
                if (a[i] != a[i - 1] && a[i] != a[1]);
                else if (b[i] != a[i - 1] && b[i] != a[1]) {
                    a[i] = b[i];
                } else {
                    a[i] = c[i];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
	}
	return 0;
}