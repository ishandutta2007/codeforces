// Problem: CF687B Remainders Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF687B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
const ll N = 1e6+5;

ll n, k, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n) scanf("%lld", &a[i]);
	ll lcm = a[1] % k;
	rep(i, 2, n) lcm = lcm / __gcd(lcm, a[i]) * a[i] % k;
	puts(lcm?"No":"Yes");
	return 0;
}