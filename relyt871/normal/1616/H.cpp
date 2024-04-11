#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 150005;
const int MAXM = MAXN * 32;

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

int n, X, pw[MAXN], pw_[MAXN], ans;
int root, tot, ch[MAXM][2], siz[MAXM];

void Insert(int &rt, int a, int d) {
    if (!rt) rt = ++tot;
    ++siz[rt];
    if (d < 0) return;
    Insert(ch[rt][(a >> d) & 1], a, d - 1);
}

int DFS(int x, int y, int d) {
    if (!x || !y || d < 0) return 0;
    int ret = 0;
    if ((X >> d) & 1) {
        Inc(ret, Mul(pw_[siz[ch[x][0]]], pw_[siz[ch[y][0]]]));
        Inc(ret, Mul(pw_[siz[ch[x][1]]], pw_[siz[ch[y][1]]]));
        int s01 = DFS(ch[x][0], ch[y][1], d - 1);
        int s10 = DFS(ch[x][1], ch[y][0], d - 1);
        Inc(ret, Add(s01, s10));
        Inc(ret, Mul(s01, s10));
        Inc(ret, Mul(s01, Add(pw_[siz[ch[x][1]]], pw_[siz[ch[y][0]]])));
        Inc(ret, Mul(s10, Add(pw_[siz[ch[x][0]]], pw_[siz[ch[y][1]]])));
        return ret;
    } else {
        Inc(ret, DFS(ch[x][0], ch[y][0], d - 1));
        Inc(ret, DFS(ch[x][1], ch[y][1], d - 1));
        return ret;
    }
}

void Work(int rt, int d) {
    if (!rt) return;
    if ((X >> d) & 1) {
        Inc(ans, pw_[siz[ch[rt][0]]]);
        Inc(ans, pw_[siz[ch[rt][1]]]);
        Inc(ans, DFS(ch[rt][0], ch[rt][1], d - 1));
        return;
    }
    Work(ch[rt][0], d - 1);
    Work(ch[rt][1], d - 1);
}

void solve() {
    read(n); read(X);
    ++X;
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        Insert(root, a, 30);
    }
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = Add(pw[i - 1], pw[i - 1]);
        pw_[i] = Sub(pw[i], 1);
    }
    Work(root, 30);
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}