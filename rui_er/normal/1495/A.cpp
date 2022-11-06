//By: Luogu@rui_er(122461)
//As a tester...
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define int long long 
using namespace std;
typedef long long ll;
const int N = 1e5+5, K = 1e5, W = 1e8;

int n, x[N<<1], y[N<<1], a[N], b[N], sN;
int gi(int l, int r) {
	int x;
	scanf("%lld", &x);
	assert(x>=l&&x<=r);
	return x;
}
void judge(int x, int l, int r) {assert(x>=l&&x<=r);}

signed main() {
	int T = gi(1, 10);
	while(T--) {
		n = gi(1, K); sN += n;
		int tA = 0, tB = 0;
		rep(i, 1, 2*n) {
			x[i] = abs(gi(-W, W));
			y[i] = abs(gi(-W, W));
			if(x[i]) a[++tA] = x[i];
			else b[++tB] = y[i];
		}
		double ans = 0.0;
		sort(a+1, a+1+n);
		sort(b+1, b+1+n);
		rep(i, 1, n) ans += sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.11lf\n", ans);
	}
	judge(sN, 1, K);
	return 0;
}