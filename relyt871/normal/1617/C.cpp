#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
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

int n, vis[MAXN], a[MAXN], t;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    t = 0;
    for (int i = 1, x; i <= n; ++i) {
        read(x);
        if (x <= n && !vis[x]) {
            vis[x] = 1;
        } else {
            a[++t] = (x + 1) / 2 - 1;
        }
    }
    sort(a + 1, a + t + 1);
    for (int i = 1, j = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (a[j] < i) {
            puts("-1");
            return;
        }
        ++j;
    }
    printf("%d\n", t);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}