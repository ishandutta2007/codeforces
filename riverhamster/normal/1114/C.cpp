#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	ll n, tn, r, ans = 0x7fffffffffffffffLL, nowr;
	int now;
	in(n); in(r);
	for(ll i=2; i*i<=r; i++){
		if(r % i == 0){
			now = 0; nowr = 0;
			do r/=i, ++now; while(r % i == 0);
			tn = n;
			while(tn) nowr += tn /= i;
			ans = min(ans, nowr / (ll)(now));
		}
	}
	if(r > 1){
		nowr = 0;
		tn = n;
		while(tn) nowr += tn /= r;
		ans = min(ans, nowr);
	}
	printf("%lld\n", ans);
	return 0;
}