//2016-06-12 22:24:58.362000
#include <bits/stdc++.h>

using namespace std;

#define NN 110
#define rep(i, a, b) for (int i = (a); i < (b); i ++)
#define inf 1000000000

int c[NN][NN];

int main() {
	
	int N, M, val, ans;
	scanf("%d%d", &N, &M);
	rep(i, 0, N) rep(j, 0, M) scanf("%d", &c[i][j]);
	ans = 0;
	rep(i, 0, N) {
		val = inf;
		rep(j, 0, M) val = min(val, c[i][j]);
		ans = max(ans, val);
	}
	printf("%d\n", ans);
	
	return 0;
}