// Problem: CF926A 2-3-numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF926A
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

ll L, R, ans;
vector<ll> pw2, pw3;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &L, &R);
	for(ll i=1;i<=R;i*=2) pw2.push_back(i);
	for(ll i=1;i<=R;i*=3) pw3.push_back(i);
	for(ll i : pw2) for(ll j : pw3) if(L <= i * j && i * j <= R) ++ans;
	printf("%lld\n", ans);
	return 0;
}