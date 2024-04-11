//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, m, a[N], b[N], c[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) buc[i] = 0;
		rep(i, 1, m) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			buc[b[i]] = 1;
		}
		rep(i, 1, n) if(!buc[i]) {
			rep(j, 1, n) if(i != j) printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}