//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1 << 16 | 5;

int T, n, k, vis[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		rep(i, 0, n-1) vis[i] = 0;
		if(n == 4 && k == 3) puts("-1");
		else if(k < n - 1) {
			printf("%d %d\n", k, n-1);
			vis[k] = vis[n-1] = 1;
			if(k) {
				printf("%d %d\n", 0, (n-1)^k);
				vis[0] = vis[(n-1)^k] = 1;
			}
			rep(i, 0, n-1) {
				if(vis[i]) continue;
				printf("%d %d\n", i, (n-1)^i);
				vis[i] = vis[(n-1)^i] = 1;
			}
		}
		else {
			printf("%d %d\n", n-2, n-1);
			vis[n-2] = vis[n-1] = 1;
			printf("%d %d\n", 3, 1);
			vis[3] = vis[1] = 1;
			printf("%d %d\n", 0, n-4);
			vis[0] = vis[n-4] = 1;
			rep(i, 0, n-1) {
				if(vis[i]) continue;
				printf("%d %d\n", i, (n-1)^i);
				vis[i] = vis[(n-1)^i] = 1;
			}
		}
	}
	return 0;
}