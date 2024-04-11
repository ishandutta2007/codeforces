#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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

int n, q, lst, vis[MAXN];
LL sum, all, a[MAXN];

void solve() {
    read(n); read(q);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        sum += a[i];
    }
    lst = -1;
    for (int i = 1, t, p, x; i <= q; ++i) {
        read(t);
        if (t == 1) {
            read(p); read(x);
            if (vis[p] < lst) {
                sum += x - all;
            } else {
                sum += x - a[p];
            }
            a[p] = x;
            vis[p] = i;
        } else {
            read(all);
            lst = i;
            sum = all * n;
        }
        printf("%lld\n", sum);
    }
}

int main() {
    solve();
    return 0;
}