#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 200005;

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
    const int MOD = 1e9 + 7;
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

int n, k, fac[MAXN], finv[MAXN];
int siz[MAXN], son[MAXN], kep1[MAXN], kep2[MAXN], ans, Ans;
vector<int> tree[MAXN];

inline int Ck(int x) {
    if (x < k) return 0;
    return Mul(fac[x], Mul(finv[k], finv[x - k]));
}

void DFS1(int u, int fa) {
    siz[u] = 1;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        DFS1(v, u);
        siz[u] += siz[v];
        Inc(son[u], Ck(siz[v]));
    }
    kep1[u] = Mul(siz[u], Sub(Ck(siz[u]), son[u]));
    Inc(ans, kep1[u]);
}

void DFS2(int u, int fa, int fans) {
    if (u > 1) {
        Dec(fans, kep1[u]);
        kep2[u] = Mul(n, Sub(Ck(n), Add(son[u], Ck(n - siz[u]))));
        Inc(fans, kep2[u]);
        Inc(Ans, fans);
    }
    for (auto v : tree[u]) {
        if (v == fa) continue;
        int tmp = fans;
        if (u == 1) {
            Dec(tmp, kep1[u]);
            Inc(tmp, Mul(n - siz[v], Sub(Ck(n - siz[v]), Sub(son[u], Ck(siz[v])))));
        } else {
            Dec(tmp, kep2[u]);
            Inc(tmp, Mul(n - siz[v], Sub(Ck(n - siz[v]), Add(Sub(son[u], Ck(siz[v])), Ck(n - siz[u])))));
        }
        DFS2(v, u, tmp);
    }
}

void solve() {
    read(n); read(k);
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }
    ans = 0;
    DFS1(1, 0);
    Ans = ans;
    DFS2(1, 0, ans);
    printf("%d\n", Ans);
}

int main() {
    solve();
    return 0;
}