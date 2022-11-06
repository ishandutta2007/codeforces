//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll n, q; 
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll lowbit(ll x) {return x&(-x);}

int main() {
	scanf("%lld%lld", &n, &q);
	while(q --> 0) {
		ll u;
		string s;
		scanf("%lld", &u);
		cin>>s;
		for(auto i : s) {
			ll d = lowbit(u);
			if(i == 'U') {
				if((u << 1) == n + 1) continue;
				u |= d << 1;
				u ^= d;
			}
			else if(i == 'L') {
				if(u & 1) continue;
				u ^= d | (d >> 1);
			}
			else {
				if(u & 1) continue;
				u ^= d >> 1;
			}
		}
		printf("%lld\n", u);
	}
    return 0;
}