// Problem: Railway System
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1687/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 505;

ll n, m, sta[N], w[N], a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll ask() {
	printf("? ");
	rep(i, 1, m) printf("%lld", sta[i]);
	puts("");
	fflush(stdout);
	ll x;
	scanf("%lld", &x);
	return x;
}
void give(ll x) {
	printf("! %lld\n", x);
	fflush(stdout);
}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, m) {
		sta[i] = 1;
		w[i] = ask();
		sta[i] = 0;
	}
	rep(i, 1, m) a[i] = i;
	sort(a+1, a+1+m, [](ll x, ll y) {
		return w[x] < w[y];
	});
	ll lst = w[a[1]], ans = w[a[1]];
	sta[a[1]] = 1;
	rep(i, 2, m) {
		sta[a[i]] = 1;
		ll now = ask();
		// printf("%lld %lld %lld\n", now, lst, w[a[i]]);
		if(now == lst + w[a[i]]) lst = now, ans += w[a[i]];
		// else if(now == lst) lst = now, ans += w[a[i]];
		else sta[a[i]] = 0;
	}
	give(ans);
	// system("pause");
	return 0;
}