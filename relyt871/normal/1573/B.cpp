#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n, a[MAXN], b[MAXN], pos[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        a[i] = a[i] / 2 + 1;
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        b[i] = b[i] / 2;
    }
    for (int i = 1; i <= n; ++i) {
        pos[b[i]] = i;
    }
    for (int i = n - 1; i >= 1; --i) {
        pos[i] = min(pos[i], pos[i + 1]);
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, i - 1 + pos[a[i]] - 1);
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