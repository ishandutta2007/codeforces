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

int n, a[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		a[i] += i;
	}
	sort(a+1, a+1+n);
	rep(i, 1, n) a[i] -= i;
	rep(i, 2, n) if(a[i-1] > a[i]) return puts(":("), 0;
	rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}