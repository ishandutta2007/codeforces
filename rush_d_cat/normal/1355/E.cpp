#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
typedef long long LL;
int n, A, R, M;
LL a[N], sum[N];
const LL inf = 1e18 + 1e17;
LL cac(int x, LL val) {
	LL y = n - x;
	LL c1 = val * x - sum[x];
	LL c2 = (sum[n] - sum[x]) - val * y;
	LL mn = min(c1, c2);
	LL tmp = mn * M + (c1 - mn) * A + (c2 - mn) * R; 
	return tmp;	
}
LL solve(int x) {
	LL res = inf;
	res = min(res, cac(x, a[x]));
	res = min(res, cac(x, a[x+1]));
	if (n * a[x] <= sum[n] && n * a[x+1] >= sum[n]) {
		LL ave = sum[n] / n;
		for (int i = ave - 1; i <= ave + 1; i ++) {
			if (i <= a[x+1] && i >= a[x]) {
				res = min(res, cac(x, i));
			}
		}
	}
	return res;
}

int main() {
	scanf("%d%d%d%d", &n,&A,&R,&M);
	M = min(A+R, M);

	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i-1] + a[i];
	}
	LL ans = inf;
	for (int i = 0; i < n; i ++) {
		ans = min(ans, solve(i));
	}
	cout << ans << endl;
}