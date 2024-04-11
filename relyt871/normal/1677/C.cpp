#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int n, a[MAXN], b[MAXN], posa[MAXN], posb[MAXN];
int vis[MAXN], m, len[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        posa[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        posb[b[i]] = i;
        vis[i] = 0;
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int l = 0;
        for (int u = i; !vis[u]; u = posa[b[u]]) {
            vis[u] = 1;
            ++l;
        }
        len[++m] = l;
    }
    sort(len + 1, len + m + 1);
    LL ans = 0;
    int l = 1, r = n;
    for (int i = 1; i <= m; ++i) {
        if (len[i] == 1) continue;
        int cur = len[i], mx = r;
        if (cur & 1) --cur;
        for (int j = 1; j <= cur; j += 2) {
            ans += r - l + r - 1 - l;
            --r; ++l;
        }
        ans += mx - r;
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}