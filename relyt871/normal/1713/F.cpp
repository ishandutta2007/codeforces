#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 19) + 5;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, a[MAXN], len;

void FWT_or(int *a) {
    for (int i = 1; i < len; i <<= 1) {
        for (int j = 0; j < len; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                a[j + k + i] ^= a[j + k];
            }
        }
    }
}

void FWT_and(int *a) {
    for (int i = 1; i < len; i <<= 1) {
        for (int j = 0; j < len; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                a[j + k] ^= a[j + k + i];
            }
        }
    }
}

void solve() {
    read(n);
    for (int i = 0; i < n; ++i) {
        read(a[i]);
    }
    for (len = 1; len < n; len <<= 1);
    FWT_or(a);
    for (int i = n; i < len; ++i) {
        a[i] = 0;
    }
    FWT_and(a);
    for (int i = n - 1; i >= 0; --i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}