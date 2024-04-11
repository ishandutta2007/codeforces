// Problem: B. Nearest Fraction
// Contest: Codeforces - Training Round #1 (1400-1700-1900-2000-2100-2200, 120min)
// URL: https://codeforces.com/group/iw2l909Oqc/contest/396416/problem/B
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
const ll N = 1e5+5;

ll x, y, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld%lld", &x, &y, &n);
	ll ansx = 0, ansy = 1, ansp = x, ansq = y;
	rep(i, 1, n) {
		ll mid = x * i / y;
		ll p1 = abs(mid * y - x * i), p2 = abs((mid + 1) * y - x * i);
		ll q = i * y;
		// debug("%lld/%lld : %lld/%lld\n%lld/%lld : %lld/%lld\n", mid, i, p1, q, mid+1, i, p2, q);
		if(p1 * ansq < ansp * q) {
			ansx = mid;
			ansy = i;
			ansp = p1;
			ansq = q;
		}
		if(p2 * ansq < ansp * q) {
			ansx = mid + 1;
			ansy = i;
			ansp = p2;
			ansq = q;
		}
	}
	ll gcd = __gcd(ansx, ansy);
	ansx /= gcd;
	ansy /= gcd;
	printf("%lld/%lld\n", ansx, ansy);
	return 0;
}