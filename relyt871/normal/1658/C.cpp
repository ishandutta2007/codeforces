#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;
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

int n, a[MAXN], b[MAXN];

void solve() {
    read(n);
    int cnt = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        a[n + i] = a[i];
        if (a[i] == 1) {
            ++cnt;
            pos = i;
        }
    }
    if (cnt != 1) {
        puts("NO");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = a[pos + i - 1];
    }
    for (int i = 2; i <= n; ++i) {
        if (b[i] > b[i - 1] + 1) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}