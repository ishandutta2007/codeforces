#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 5005;

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
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
}
using namespace ModCalculator;

int n, k, stk[MAXN], top;
char s[MAXN];
int pre[MAXN], nxt[MAXN];
int C[MAXN][MAXN];

void solve() {
    read(n); read(k);
    scanf("%s", s + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (s[i - 1] == '1') pre[i] = i - 1;
    }
    nxt[n + 1] = n + 1;
    for (int i = n; i >= 1; --i) {
        nxt[i] = nxt[i + 1];
        if (s[i + 1] == '1') nxt[i] = i + 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            stk[++top] = i;
        }
    }
    if (k == 0 || top < k) {
        printf("1\n");
        return;
    }
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    int ans = C[nxt[stk[k]] - 1][k];
    for (int i = 2; i + k - 1 <= top; ++i) {
        int l = pre[stk[i]] + 1, r = nxt[stk[i + k - 1]] - 1;
        for (int j = l + k - 1; j <= r; ++j) {
            if (j == stk[i + k - 1]) continue;
            Inc(ans, C[j - l][k - 1]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}