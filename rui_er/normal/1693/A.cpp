// Problem: CF1693A Directional Increase
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1693A
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		while(n >= 1 && !a[n]) --n;
		if(!n) puts("Yes");
		else {
			rep(i, 2, n) a[i] += a[i-1];
			if(a[n] || *min_element(a+1, a+n) <= 0) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}