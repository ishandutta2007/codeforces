//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1 << 22;

int n, a[N], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		ans[a[i]] = a[i];
	}
	rep(i, 0, 21) {
		rep(sta, 0, (1<<22)-1) {
			if(((sta >> i) & 1) && ~ans[sta^(1<<i)] && !~ans[sta]) {
				ans[sta] = ans[sta^(1<<i)];
			}
		}
	}
	rep(i, 1, n) {
		int k = ((1 << 22) - 1) ^ a[i];
		printf("%d%c", ans[k], " \n"[i==n]);
	}
	return 0;
}