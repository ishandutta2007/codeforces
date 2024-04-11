// LUOGU_RID: 94002773
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll k, a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(ll x) {
	if(x < 0) x = -x;
	return x / k;
}

int main() {
	scanf("%lld%lld%lld", &k, &a, &b);
	if(b < 0) printf("%lld\n", calc(a) - calc(b + 1));
	else if(a > 0) printf("%lld\n", calc(b) - calc(a - 1));
	else printf("%lld\n", calc(a) + calc(b) + 1);
	return 0;
}