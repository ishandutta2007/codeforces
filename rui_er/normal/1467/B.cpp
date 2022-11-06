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
const int N = 3e5+5;

int n, a[N];
int count(int x) {
	if(x == 1 || x == n) return 0;
	return (a[x] > a[x-1] && a[x] > a[x+1]) || (a[x] < a[x-1] && a[x] < a[x+1]);
}

int main() {
	mulT0 {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int ans = 0, ma = 0;
		rep(i, 2, n-1) {
			int qwq = a[i], qaq = count(i-1) + count(i) + count(i+1);
			a[i] = a[i-1]; ma = max(ma, qaq-(count(i-1)+count(i)+count(i+1)));
			a[i] = a[i+1]; ma = max(ma, qaq-(count(i-1)+count(i)+count(i+1)));
			a[i] = qwq;
		}
		rep(i, 2, n-1) ans += count(i);
		printf("%d\n", ans-ma);
	}
	return 0;
}