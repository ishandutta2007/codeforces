//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const ll N = 55;

ll n, m, fa[N], ans = 1;
void init(ll x) {rep(i, 1, x) fa[i] = i;}
ll find(ll x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool merge(ll x, ll y) {ll u = find(x), v = find(y); return u == v ? 0 : fa[u] = v;}

int main() {
	scanf("%lld%lld", &n, &m);
	init(n);
	while(m--) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		ans <<= merge(u, v);
	}
	printf("%lld\n", ans);
	return 0;
}