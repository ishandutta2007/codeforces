//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

ll T, a, b; 
bool isPrime(ll x) {
	ll _ = sqrt(x);
	rep(i, 2, _) if(!(x % i)) return 0;
	return 1;
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &a, &b);
		if(a - b == 1 && isPrime(a+b)) puts("YES");
		else puts("NO");
	}
	return 0;
}