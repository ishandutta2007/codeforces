//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

ll T, a, b, k;

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld%lld", &a, &b, &k);
		ll delta = a - b, rnds = (k >> 1), left = (k & 1);
		printf("%lld\n", delta*rnds+a*left);
	}
	return 0;
}