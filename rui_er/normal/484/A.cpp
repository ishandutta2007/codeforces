//By: Luogu@rui_er(122461)..
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

ll T, l, r;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &l, &r);
		rep(i, 0, 62) {
			if((l | (1LL << i)) > r) break;
			l |= 1LL << i;
		}
		printf("%lld\n", l);
	}
	return 0;
}