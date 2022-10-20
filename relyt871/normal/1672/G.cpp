#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 2005;
const int NN = 4005;

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

namespace ModCalculator {
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

char g[N][N];
int pw[N * N];
int n, m, d[NN], vis[NN], nc, mc, dc;
vector<int> gr[NN];

void DFS(int u) {
    vis[u] = 1;
    ++nc;
    dc ^= d[u];
    for (auto v : gr[u]) {
        ++mc;
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void solve() {
    read(n); read(m);
    pw[0] = 1;
    for (int i = 1; i <= n * m; ++i) {
        pw[i] = Mul(pw[i - 1], 2);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%s", g[i] + 1);
    }
    if ((n & 1) && !(m & 1)) {
        swap(n, m);
        for (int i =  1; i <= 2000; ++i) {
            for (int j = i + 1; j <= 2000; ++j) {
                swap(g[i][j], g[j][i]);
            }
        }
    }

    if (!(n & 1) && !(m & 1)) {

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cnt += (g[i][j] == '?');
            }
        }
        printf("%d\n", pw[cnt]);

    } else if ((n & 1) ^ (m & 1)) {

        int cnt = 0;
        bool ok0 = 1, ok1 = 1;
        for (int i = 1; i <= n; ++i) {
            int cur = 0, val = 0;
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == '?') {
                    ++cur;
                } else {
                    val ^= (g[i][j] - '0');
                }
            }
            if (!cur) {
                (val? ok0 : ok1) = 0;
            } else {
                cnt += cur - 1;
            }
        }
        printf("%d\n", Mul(pw[cnt], ok0 + ok1));

    } else {

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == '1') {
                    d[i] ^= 1;
                    d[n + j] ^= 1;
                }
                if (g[i][j] == '?') {
                    gr[i].push_back(n + j);
                    gr[n + j].push_back(i);
                }
            }
        }
        int ans0 = 1, ans1 = 1;
        int cur0 = 0, cur1 = 0;
        for (int i = 1; i <= n + m; ++i) {
            if (vis[i]) continue;
            nc = mc = dc = 0;
            DFS(i);
            mc = mc / 2 - (nc - 1);
            if (nc & 1) {
                cur0 = (dc? 0 : pw[mc]);
                cur1 = (!dc? 0 : pw[mc]);
            } else {
                cur0 = cur1 = (dc? 0 : pw[mc]);
            }
            ans0 = Mul(ans0, cur0);
            ans1 = Mul(ans1, cur1);
        }
        printf("%d\n", Add(ans0, ans1));

    }
}

int main() {
    solve();
    return 0;
}