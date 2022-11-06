//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, l, r, k, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d%d", &n, &l, &r, &k);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a+1, a+1+n);
		int ans = 0;
		rep(i, 1, n) {
			if(a[i] < l) continue;
			if(a[i] > r) break;
			if(k >= a[i]) {
				++ans;
				k -= a[i];
			}
			else break;
		}
		printf("%d\n", ans);
	}
    return 0;
}