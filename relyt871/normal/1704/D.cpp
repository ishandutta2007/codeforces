#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, m;

void solve() {
    read(n); read(m);
    LL mn = 2e18, mx = 0;
    int mnpos = -1;
    for (int i = 1; i <= n; ++i) {
        LL sum = 0, ssum = 0, x;
        for (int j = 1; j <= m; ++j) {
            read(x);
            sum += x;
            ssum += sum;
        }
        if (ssum < mn) {
            mn = ssum;
            mnpos = i;
        }
        mx = max(mx, ssum);
    }
    printf("%d %lld\n", mnpos, mx - mn);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}