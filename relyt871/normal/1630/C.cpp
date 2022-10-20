#include<bits/stdc++.h>
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

int n, a[MAXN], lst[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        lst[a[i]] = i;
    }
    int ans = 0, p = 1, far = 0;
    while (p <= n) {
        int q = lst[a[p]], cnt = 0, mx = 0, mxpos = 0;
        for (int i = max(far, p + 1); i < q; ++i) {
            ++cnt;
            if (lst[a[i]] > mx) {
                mx = lst[a[i]];
                mxpos = i;
            }
        }
        far = q;
        if (mx <= q) {
            ans += cnt;
            p = q + 1;
        } else {
            ans += cnt - 1;
            p = mxpos;
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}