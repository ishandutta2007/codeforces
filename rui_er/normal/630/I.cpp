//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

ll n, ans[4] = {0, 0, 4, 24};
ll qpow(ll a, ll b) {
	ll res = 1;
	for(;b;b>>=1,a*=a) if(b&1) res *= a;
	return res;
} 
ll calc(ll n) {
	if(n <= 3) return ans[n];
	return 24 * qpow(4, n-3) + (n - 3) * 36 * qpow(4, n-4);
}

int main() {
	scanf("%lld", &n);
	printf("%lld\n", calc(n));
	return 0;
}