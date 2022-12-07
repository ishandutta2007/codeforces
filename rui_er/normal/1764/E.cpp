// LUOGU_RID: 96329362
// Problem: CF1764E Doremy's Number Line
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1764E
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
const ll N = 1e5+5;

ll T, n, k, mx[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Item {
	ll a, b, sum;
}a[N];

int main() {
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) {
			scanf("%lld%lld", &a[i].a, &a[i].b);
			a[i].sum = a[i].a + a[i].b;
		}
		if(a[1].a + a[1].b < k) puts("NO");
		else if(a[1].a >= k) puts("YES");
		else {
			sort(a+2, a+1+n, [](const Item& a, const Item& b) {
				if(a.a != b.a) return a.a > b.a;
				return a.b > b.b;
			});
			per(i, n, 1) mx[i] = max(mx[i+1], a[i].sum);
			k -= a[1].b;
			ll ok = 0;
			rep(i, 2, n) {
				if(mx[i+1] >= k || a[i].a >= k) {ok = 1; break;}
				if(a[i].sum >= k) k -= a[i].b;
			}
			puts(ok ? "YES" : "NO");
			rep(i, 0, n+1) mx[i] = 0;
		}
	}
	return 0;
}