#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1005;
const int MAXS = (1 << 17) + 5;

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

char s[N];
int n, q, blank, bin[18], pw[18][N];
int len, f[18][MAXS];

inline void Count(int l, int r) {
    int must = 0, wow = blank;
    for (; 1 <= l && r <= n; --l, ++r) {
        if (s[l] == '?' && s[r] == '?') {
            if (l < r) --wow; //attention
        } else if (s[l] == '?') {
            must |= bin[s[r] - 'a'];
            --wow;
        } else if (s[r] == '?') {
            must |= bin[s[l] - 'a'];
            --wow;
        } else if (s[l] != s[r]) {
            return;
        }
        for (int i = 1; i <= 17; ++i) {
            Inc(f[i][must], pw[i][wow]);
        }
    }
}

void solve() {
    read(n);
    len = (1 << 17);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        blank += (s[i] == '?');
    }
    for(int i = 0; i <= 17; ++i) {
        bin[i] = (1 << i);
        pw[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            pw[i][j] = Mul(pw[i][j - 1], i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        Count(i, i);
        if (i < n) {
            Count(i, i + 1);
        }
    }
    for (int c = 1; c <= 17; ++c) {
        for (int i = 1; i < len; i <<= 1) {
            for (int j = 0; j < len; j += (i << 1)) {
                for (int k = 0; k < i; ++k) {
                    Inc(f[c][j + k + i], f[c][j + k]);
                }
            }
        }
    }

    read(q);
    while (q--) {
        scanf("%s", s + 1);
        int m = strlen(s + 1), state = 0;
        for (int i = 1; i <= m; ++i) {
            state |= bin[s[i] - 'a'];
        }
        printf("%d\n", f[m][state]);
    }
}

int main() {
    solve();
    return 0;
}