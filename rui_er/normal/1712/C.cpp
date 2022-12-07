// LUOGU_RID: 94323935
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, a[N], b[N], c[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		b[n] = 1;
		per(i, n-1, 1) {
			if(a[i] > a[i+1]) break;
			b[i] = 1;
		}
		rep(i, 1, n) {
			if(!b[i]) c[a[i]] = 1;
			else break;
		}
		per(i, n, 1) {
			if(c[a[i]]) b[i] = 0;
			if(i < n && b[i] > b[i+1]) {
				b[i] = 0;
				c[a[i]] = 1;
			}
		}
		printf("%lld\n", accumulate(c+1, c+1+n, 0LL));
		rep(i, 1, n) a[i] = b[i] = c[i] = 0;
	}
	return 0;
}