#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
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

struct UFS {
    int f[MAXN], tag[MAXN];

    int getf(int x) {
        return (f[x] == x)? x : f[x] = getf(f[x]);
    }

    inline void puttag(int x) {
        tag[getf(x)] = 1;
    }

    inline void Merge(int x, int y) {
        f[getf(x)] = getf(y);
    }

    inline bool adj(int x, int y) {
        return (getf(x) == getf(y));
    }

    inline int gettag(int x) {
        return tag[getf(x)];
    }
} ufs[30];

int n, m, q, U[MAXN], V[MAXN], W[MAXN];

int Query() {
    int u, v;
    read(u); read(v);
    for (int j = 0; j < 30; ++j) {
        if (ufs[j].adj(u, v)) {
            return 0;
        }
    }
    for (int j = 1; j < 30; ++j) {
        if (ufs[j].gettag(u)) {
            return 1;
        }
    }
    return 2;
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 30; ++j) {
            ufs[j].f[i] = i;
        }
    }
    for (int i = 1; i <= m; ++i) {
        read(U[i]); read(V[i]); read(W[i]);
        for (int j = 0; j < 30; ++j) {
            if ((W[i] >> j) & 1) {
                ufs[j].Merge(U[i], V[i]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (W[i] & 1) continue;
        for (int j = 0; j < 30; ++j) {
            ufs[j].puttag(U[i]);
            ufs[j].puttag(V[i]);
        }
    }

    read(q);
    while (q--) {
        printf("%d\n", Query());
    }
}

int main() {
    solve();
    return 0;
}