#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, a[MAXN], vis[MAXN], suf[MAXN];
int ans[MAXN], len;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int mex = 0;
    for (int i = n; i >= 1; --i) {
        vis[a[i]] = 1;
        while (vis[mex]) ++mex;
        suf[i] = mex;
    }
    for (int i = 1; i <= n; ++i) {
        vis[a[i]] = 0;
    }
    len = 0;
    for (int i = 1, j; i <= n; i = j + 1) {
        ans[++len] = suf[i];
        mex = 0;
        for (j = i; ; ++j) {
            vis[a[j]] = 1;
            while (vis[mex]) ++mex;
            if (mex == suf[i]) break;
        }
        for (int k = i; k <= j; ++k) {
            vis[a[k]] = 0;
        }
    }
    printf("%d\n", len);
    for (int i = 1; i < len; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[len]);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}