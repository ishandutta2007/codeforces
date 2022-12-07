// LUOGU_RID: 96073282
// Problem: CF938C Constructing Tests
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF938C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, x;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld", &x);
		if(!x) puts("1 1");
		else {
			bool ok = 0;
			for(ll i = 1; i * i < x; i++) {
				if(!(x % i)) {
					ll j = x / i;
					if((i & 1) != (j & 1)) continue;
					ll n = (i + j) / 2, ndm = (j - i) / 2, m = n / ndm;
					if(n / m == ndm) {
						ok = 1;
						printf("%lld %lld\n", n, m);
						break;
					}
				}
			}
			if(!ok) puts("-1");
		}
	}
	return 0;
}