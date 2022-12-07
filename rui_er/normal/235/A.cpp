// LUOGU_RID: 96166234
// Problem: CF235A LCM Challenge
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF235A
// Memory Limit: 250 MB
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

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll lcm(ll a, ll b) {return a / __gcd(a, b) * b;}

int main() {
	ll n;
	scanf("%lld", &n);
	if(n <= 2) return printf("%lld\n", n)&0;
	ll ans = 0;
	rep(i, n-3, n) rep(j, i+1, n) rep(k, j+1, n) chkmax(ans, lcm(i, lcm(j, k)));
	printf("%lld\n", ans);
	return 0;
}