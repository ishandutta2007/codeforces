// LUOGU_RID: 96193533
// Problem: CF413C Jeopardy!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF413C
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
const ll N = 105;

ll n, m, a[N], p[N], vis[N], spj[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) {
		scanf("%lld", &p[i]);
		vis[p[i]] = 1;
		spj[i] = a[p[i]];
	}
	ll ans = 0;
	rep(i, 1, n) if(!vis[i]) ans += a[i];
	sort(spj+1, spj+1+m, greater<ll>());
	rep(i, 1, m) ans = max(ans + spj[i], ans * 2);
	printf("%lld\n", ans);
	return 0;
}