//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int xsum = 0;
		rep(i, 1, n) xsum ^= a[i];
		if(!xsum) puts("YES");
		else {
			int now = 0, cnt = 0;
			rep(i, 1, n-1) {
				now ^= a[i];
				if(now == xsum) {
					now = 0;
					++cnt;
				}
			}
			puts(cnt>=2?"YES":"NO");
		}
	}
	return 0;
}