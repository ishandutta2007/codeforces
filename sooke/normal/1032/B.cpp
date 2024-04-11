#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int n, p;
std::string s;

inline void check(int r, int c) {
    if (r * c < n) { return; }
    int d = r * c - n;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j <= r; j++) {
            if (j * i + (r - j) * (i + 1) == d) {
                printf("%d %d\n", r, c);
                for (int k = 1; k <= j; k++) {
                    for (int l = 1; l <= c - i; l++) { putchar(s[p++]); }
                    for (int l = 1; l <= i; l++) { putchar('*'); }
                    putchar('\n');
                }
                for (int k = j + 1; k <= r; k++) {
                    for (int l = 1; l <= c - i - 1; l++) { putchar(s[p++]); }
                    for (int l = 1; l <= i + 1; l++) { putchar('*'); }
                    putchar('\n');
                }
                exit(0);
            }
        }
    }
}

int main() {
    std::cin >> s; n = s.size();
    if (n <= 20) { std::cout << "1 " << n << "\n" << s << "\n"; return 0; }
    for (int i = 2; i <= 5; i++) {
        for (int j = 1; j <= 20; j++) { check(i, j); }
    }
    return 0;
} //