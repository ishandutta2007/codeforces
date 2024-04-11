#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MOD = 998244353;

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

int n, s, m, a[MAXN], b[MAXN], bpos[MAXN], c[MAXN];

int solve() {
    read(n); read(s);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        bpos[i] = 0;
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        if (b[i] != -1) {
            bpos[b[i]] = i;
        } else {
            c[++m] = a[i];
        }
    }
    sort(c + 1, c + m + 1);
    int ans = 1;
    for (int i = 1, j = 0, used = 0; i <= n; ++i) {
        int k = bpos[i];
        if (k == 0) {
            while (j < m && c[j + 1] <= i + s) {
                ++j;
            }
            if (j <= used) return 0;
            ans = 1LL * ans * (j - used) % MOD;
            ++used;
        } else {
            if (a[k] > i + s) return 0;
        }
    }
    return ans;
}

int main() {
    int T; read(T);
    while (T--) {
        printf("%d\n", solve());
    }
    return 0;
}