//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, A, B;
struct Node {
	ll a, b;
	friend bool operator < (const Node &x, const Node &y) {return x.a < y.a;}
}a[N];

int main() {
	mulT0 {
		scanf("%lld%lld%lld", &A, &B, &n);
		rep(i, 1, n) scanf("%lld", &a[i].a);
		rep(i, 1, n) scanf("%lld", &a[i].b);
		sort(a+1, a+1+n);
		ll _ = 1;
		rep(i, 1, n) {
			ll atk = a[i].b / A + (a[i].b % A > 0);
			B -= atk * a[i].a;
			if(B <= 0) {
				if(i == n) {
					B += atk * a[i].a;
					atk = B / a[i].a + (B % a[i].a > 0);
					a[i].b -= atk * A;
					if(a[i].b > 0) {
						puts("NO");
						_ = 0;
						break;
					}
				}
				else {
					puts("NO");
					_ = 0;
					break;
				}
			}
		}
		if(_) puts("YES");
	}
	return 0;
}