//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e3+5;

ll n, dis[N][N], ok[N], tot;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dot {
	ll x, y, z;
	Dot(ll a=0, ll b=0, ll c=0) : x(a), y(b), z(c) {}
	~Dot() {}
}a[N], d[N*N];
ll pw(ll x) {return x * x;}
ll dis2(const Dot& a, const Dot& b) {return pw(a.x - b.x) + pw(a.y - b.y) + pw(a.z - b.z);}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
	fill(ok+1, ok+1+n, 1);
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = dis2(a[i], a[j]);
	rep(i, 1, n) rep(j, i+1, n) d[++tot] = Dot(i, j, dis[i][j]);
	sort(d+1, d+1+tot, [](const Dot& a, const Dot& b) {
		return a.z < b.z;
	});
	ll now = 1;
	rep(i, 1, n/2) {
		while(now < tot && (!ok[d[now].x] || !ok[d[now].y])) ++now;
		printf("%lld %lld\n", d[now].x, d[now].y);
		ok[d[now].x] = ok[d[now].y] = 0;
	}
	return 0;
}