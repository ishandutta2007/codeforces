//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int T, n, a[N], b[N], ans[N], arr[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%1d", &a[i]);
			b[i] = a[i];
		}
		sort(b+1, b+1+n);
		b[n+1] = 10;
		int now = 1;
		rep(i, 1, n) {
			if(a[i] == b[now]) {
				ans[i] = 1;
				++now;
			}
			else ans[i] = 2;
		}
		int tms = 0, ok = 1;
		rep(i, 1, n) if(ans[i] == 1) arr[++tms] = a[i];
		rep(i, 1, n) if(ans[i] == 2) arr[++tms] = a[i];
		rep(i, 2, n) ok &= arr[i-1] <= arr[i];
		if(!ok) putchar('-');
		else rep(i, 1, n) printf("%d", ans[i]);
		puts("");
	}
	return 0;
}