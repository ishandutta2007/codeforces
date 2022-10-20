#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 500005;

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

int n, vis[205];

void solve() {
    mset(vis, 0);
    read(n);
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        ++vis[100 + x];
    }
    int ans = (vis[100] > 0);
    for (int i = 1; i <= 100; ++i) {
        ans += min(2, vis[100 + i] + vis[100 - i]);
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}