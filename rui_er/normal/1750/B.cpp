// LUOGU_RID: 93139861
// Problem: B. Maximum Substring
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/B
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
const ll N = 2e5+5;

ll T, n, a[N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld%s", &n, s+1);
		rep(i, 1, n) a[i] = s[i] - '0';
		ll cnt = 0, mx = 0, now = 0;
		rep(i, 1, n) {
			cnt += a[i];
			if(a[i] == a[i-1]) ++now;
			else now = 1;
			chkmax(mx, now);
		}
		printf("%lld\n", max(cnt * (n - cnt), mx * mx));
	}
	return 0;
}