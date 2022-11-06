//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], m, b[N], c[N], buc[N*3], tot, cnt[N*3], ans = 1, tpA, tpB;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), buc[++tot] = a[i];
	scanf("%d", &m);
	rep(i, 1, m) scanf("%d", &b[i]), buc[++tot] = b[i];
	rep(i, 1, m) scanf("%d", &c[i]), buc[++tot] = c[i];
	sort(buc+1, buc+1+tot);
	tot = unique(buc+1, buc+1+tot) - 1 - buc;
	rep(i, 1, n) a[i] = lower_bound(buc+1, buc+1+tot, a[i]) - buc;
	rep(i, 1, m) {
		b[i] = lower_bound(buc+1, buc+1+tot, b[i]) - buc;
		c[i] = lower_bound(buc+1, buc+1+tot, c[i]) - buc;
	}
	rep(i, 1, n) ++cnt[a[i]];
	rep(i, 1, m) {
		if(cnt[b[i]] > tpA) {
			ans = i;
			tpA = cnt[b[i]];
			tpB = cnt[c[i]];
		}
		else if(cnt[b[i]] == tpA && cnt[c[i]] > tpB) {
			ans = i;
			tpB = cnt[c[i]];
		}
	}
	printf("%d\n", ans);
	return 0;
}