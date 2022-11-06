//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 105;

int n, m, a[N];

int main() {
	mulT0 {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a+1, a+1+n, greater<int>());
		int sum = 0, ok = 1;
		rep(i, 1, n) {
			sum += a[i];
			if(sum > m) break;
			if(sum == m) {
				if(i != n) {swap(a[i], a[i+1]); break;}
				else {ok = 0; break;}
			}
		}
		if(!ok) puts("NO");
		else {
			puts("YES");
			rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
		}
	}
	return 0;
}