//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, k, m, b[N], buc[N], pre[N], suf[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &n, &k, &m);
		rep(i, 1, m) {
			scanf("%d", &b[i]);
			++buc[b[i]];
		}
		rep(i, 1, n) pre[i] = pre[i-1] + !buc[i];
		per(i, n, 1) suf[i] = suf[i+1] + !buc[i];
		int del = n - m;
		if(del % (k - 1)) puts("NO");
		else {
			int ok = 0;
			rep(i, 1, m) {
				if(pre[b[i]-1] >= k / 2 && suf[b[i]+1] >= k / 2) {
					ok = 1;
					break;
				}
			}
			puts(ok?"YES":"NO");
		}
		rep(i, 0, n+1) b[i] = buc[i] = pre[i] = suf[i] = 0;
	}
	return 0;
}