#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

char s[MAXN];
int n, x[MAXN], y[MAXN], z[MAXN], k;

inline bool ccmp(int i, int j) {
    return (s[i] < s[j]);
}

inline bool cmp(int i, int j) {
    if (y[i] ^ y[j]) return (y[i] < y[j]);
    return (y[i ^ k] < y[j ^ k]);
}

void solve() {
    read(n);
    scanf("%s", s);
    n = (1 << n);
    for (int i = 0; i < n; ++i) {
        x[i] = i;
    }
    sort(x, x + n, ccmp);
    y[x[0]] = 1;
    for (int i = 1; i < n; ++i) {
        y[x[i]] = y[x[i - 1]] + ccmp(x[i - 1], x[i]);
    }
    for (k = 1; k < n; k <<= 1) {
        sort(x, x + n, cmp);
        z[x[0]] = 1;
        for (int i = 1; i < n; ++i) {
            z[x[i]] = z[x[i - 1]] + cmp(x[i - 1], x[i]);
        }
        for (int i = 0; i < n; ++i) {
            y[i] = z[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        putchar(s[i ^ x[0]]);
    }
    puts("");
}

int main() {
    solve();
    return 0;
}