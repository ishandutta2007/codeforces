//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, lim = 1e9;

int n, k, a[N], ans;
map<int, int> vis;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	rep(i, 1, n) {
		if(!vis[a[i]]) {
			++ans;
			if(a[i] <= lim / k) vis[a[i]*k] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}