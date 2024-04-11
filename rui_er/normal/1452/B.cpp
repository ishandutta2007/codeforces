//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll T, n, x; 

int main() {
	scanf("%lld", &T);
	while(T--) {
		ll s = 0, mx = 0, ans = 0;
		scanf("%lld", &n);
		rep(i, 1, n) {scanf("%lld", &x); s += x; mx = max(mx, x);}
		if(s % (n - 1)) ans = max((s/(n-1)+1)*(n-1), mx*(n-1));
		else ans = max(s, mx*(n-1));
		printf("%lld\n", ans-s);
	}
	return 0;
}