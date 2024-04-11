//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
const int N = 2e5+5, inf = 0x3f3f3f3f;

int T, n, a[N], b[N], qwq[N], lst[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		rep(i, 1, n) lst[i] = qwq[i] = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b+1, b+1+n);
		int tot = unique(b+1, b+1+n) - b, ans = inf;
		rep(i, 1, n) a[i] = lower_bound(b+1, b+1+n, a[i]) - b;
		rep(i, 1, n) {
			lst[i] = qwq[a[i]];
			qwq[a[i]] = i;
			if(lst[i]) chkmin(ans, i-lst[i]+1);
		}
		printf("%d\n", ans==inf?-1:ans);
	}
	return 0;
}