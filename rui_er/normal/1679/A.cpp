// Problem: A. AvtoBus
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, n;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		if(n < 4 || (n & 1)) puts("-1");
		else {
			ll mn = !(n % 6) ? n / 6
			      : n % 6 == 4 ? (n - 4) / 6 + 1
			      : (n - 8) / 6 + 2;
			ll mx = !(n % 4) ? n / 4
			      : (n - 6) / 4 + 1;
			printf("%lld %lld\n", mn, mx);
		}
	}
	return 0;
}