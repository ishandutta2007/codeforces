// LUOGU_RID: 96187560
// Problem: CF175C Geometry Horse
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF175C
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
const ll N = 1e3+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, m, p[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Item {
	ll k, c;
}a[N];

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld%lld", &a[i].k, &a[i].c);
	scanf("%lld", &m);
	rep(i, 1, m) scanf("%lld", &p[i]);
	p[m+1] = inf;
	sort(a+1, a+1+n, [](const Item& a, const Item& b) {
		return a.c < b.c;
	});
	ll now = 0, f = 1, ans = 0;
	rep(i, 1, n) {
		while(a[i].k) {
			ll cnt = min(a[i].k, p[f] - now);
			ans += f * a[i].c * cnt;
			a[i].k -= cnt;
			now += cnt;
			if(f <= m && now == p[f]) ++f;
		}
	}
	printf("%lld\n", ans);
	return 0;
}