#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 1005;

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

const int MOD = 998244353;
const int MOD2 = 1004535809;
inline void Inc(int &x, int y) {
    x += y; if (x >= MOD) x -= MOD;
}
inline void Inc2(int &x, int y) {
    x += y; if (x >= MOD2) x -= MOD2;
}

int n, m, a[N], deg[N], q[N], head, tail, tmp[N], tot;
vector<int> g[N];

struct Node {
    int ufs[N], later, later2;
    int getf(int x) {
        return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
    }
    void init() {
        for (int i = 1; i <= n + 1; ++i) {
            ufs[i] = i;
        }
        later = 0;
    }
    void set_busy(int x) {
        int y = getf(x);
        if (y <= n) {
            ufs[y] = y + 1;
        } else {
            Inc(later, 1);
            Inc2(later2, 1);
        }
    }
    bool is_busy(int x) {
        return getf(x) != x;
    }
    int getans() {
        if (later && later2) {
            int ans = n;
            Inc(ans, later);
            return ans;
        } else {
            for (int i = n; i >= 1; --i) {
                if (is_busy(i)) return i;
            }
            return 0;
        }
    }
} dp[N];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        dp[i].init();
        for (int j = 1; j <= a[i] && j <= n; ++j) {
            dp[i].set_busy(j);
        }
        if (a[i] > n) {
            dp[i].later = (a[i] - n) % MOD;
            dp[i].later2 = (a[i] - n) % MOD2;
        }
        g[i].clear();
        deg[i] = 0;
    }
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        g[u].push_back(v);
        ++deg[v];
    }
    head = 1, tail = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            q[++tail] = i;
        }
    }
    while (head <= tail) {
        int u = q[head++];
        tot = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[u].is_busy(i)) {
                tmp[++tot] = i;
            }
        }
        for (auto v : g[u]) {
            for (int i = 1; i <= tot; ++i) {
                dp[v].set_busy(tmp[i] + 1);
            }
            Inc(dp[v].later, dp[u].later);
            Inc2(dp[v].later2, dp[u].later2);
            if (--deg[v] == 0) {
                q[++tail] = v;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0) {
            printf("%d\n", dp[i].getans());
            return;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}