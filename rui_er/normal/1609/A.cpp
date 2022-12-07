// LUOGU_RID: 95054350
// Problem: A. Divide and Multiply
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/A
// Memory Limit: 256 MB
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
const ll N = 20;

ll T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld", &n);
		ll cnt = 0;
		rep(i, 1, n) {
			scanf("%lld", &a[i]);
			for(; !(a[i] & 1); a[i] >>= 1) ++cnt;
		}
		sort(a+1, a+1+n, greater<ll>());
		printf("%lld\n", accumulate(a+2, a+1+n, 0LL) + a[1] * (1LL << cnt));
	}
	return 0;
}