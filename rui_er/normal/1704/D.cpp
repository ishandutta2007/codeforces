// Problem: D. Magical Array
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll N = 3e5+5;

ll T, n, m, sum2[N], tmp[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) {
			ll x = 0, sum = 0, now = 0;
			rep(j, 1, m) {
				scanf("%lld", &x);
				sum += x;
				now += sum;
			}
			tmp[i] = sum2[i] = now;
		}
		sort(tmp+1, tmp+1+n);
		rep(i, 1, n) {
			if(sum2[i] != tmp[2]) {
				printf("%lld %lld\n", i, tmp[2]-sum2[i]);
				break;
			}
		}
	}
	return 0;
}