#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
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

int len, lenv, rev[MAXN], w1[MAXN], w2[MAXN];

void prework(int m) {
    int bit = -1;
    for (len = 1; len < m; len <<= 1) ++bit;
    lenv = Inv(len);
    for (int i = 0; i < len; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit);
    }
    int Gi = 3, Gv = Inv(Gi);
    for (int i = 1; i < len; i <<= 1) {
        int wk1 = Ksm(Gi, MOD / (i << 1)), wnk1 = 1;
        int wk2 = Ksm(Gv, MOD / (i << 1)), wnk2 = 1;
        for (int k = 0; k < i; ++k) {
            w1[i + k] = wnk1;
            wnk1 = Mul(wnk1, wk1);
            w2[i + k] = wnk2;
            wnk2 = Mul(wnk2, wk2);
        }
    }
}

void NTT(int *a, int type) {
    int *w = (type == 1? w1 : w2);
    for (int i = 0; i < len; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int i = 1; i < len; i <<= 1) {
        for (int j = 0; j < len; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                int x = a[j + k], y = Mul(w[i + k], a[j + k + i]);
                a[j + k] = Add(x, y);
                a[j + k + i] = Sub(x, y);
            }
        }
    }
    if (type == 1) return;
    for (int i = 0; i < len; ++i) {
        a[i] = Mul(a[i], lenv);
    }
}

int n, K, A;
int F[MAXN], G[MAXN];

void solve() {
    read(n); read(K); read(A);
    prework((K + 1) << 1);
    for (int i = 0; i <= K; ++i) {
        F[i] = 1;
    }
    for (int j = 2; j <= n; ++j) {
        for (int i = 0; i <= K; ++i) {
            G[i] = F[i];
        }
        fill(G + K + 1, G + len, 0);
        NTT(G, 1);
        for (int i = 0; i < len; ++i) {
            G[i] = Mul(G[i], G[i]);
        }
        NTT(G, -1);
        int suf = 0;
        for (int i = K * 2; i > K; --i) {
            Inc(suf, G[i]);
        }
        for (int i = K; i >= 0; --i) {
            F[i] = Add(suf, Mul(G[i], K - i + 1));
            Inc(suf, G[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= A; ++i) {
        Inc(ans, Mul(F[i], F[A - i]));
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}