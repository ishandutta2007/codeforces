//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, k, a[N], b[N], s[N], mx[N], L, R, ans;
bool check(int M) {
	rep(i, 1, n) {
		b[i] = a[i] < M ? -1 : 1;
		s[i] = s[i-1] + b[i];
		mx[i] = min(mx[i-1], s[i]);
		if(i >= k && s[i] - mx[i-k] > 0) return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	L = 1; R = n; ans = -1;
	while(L <= R) {
		int M = (L + R) >> 1;
		if(check(M)) ans = M, L = M + 1;
		else R = M - 1;
	}
	printf("%d\n", ans);
	return 0;
}