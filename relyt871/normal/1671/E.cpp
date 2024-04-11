#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = (1 << 18) + 5;
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

int n, lim, ans;
char s[MAXN];

string DFS(int u) {
    if (u >= lim) {
        return string(1, s[u]);
    }
    string l = DFS(u << 1);
    string r = DFS((u << 1) | 1);
    if (r > l) {
        swap(l, r);
    }
    if (l != r) {
        ans = 1LL * ans * 2 % MOD;
    }
    return string(1, s[u]) + l + r;
}

void solve() {
    read(n);
    scanf("%s", s + 1);
    lim = (1 << (n - 1));
    DFS(ans = 1);
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}