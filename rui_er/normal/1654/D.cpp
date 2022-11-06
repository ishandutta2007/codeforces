//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 998244353;

int T, n, p[N], tot, tab[N], buc[N], mx[N], val[N];
vector<tuple<int, int> > divisor[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Fact {
	int i, j, x, y;
	Fact(int a=0, int b=0, int c=0, int d=0) : i(a), j(b), x(c), y(d) {}
	~Fact() {}
}a[N];
vector<Fact> e[N];
void sieve(int lim) {
	rep(i, 2, lim) {
		if(!tab[i]) p[++tot] = i;
		for(int j=1;j<=tot&&i*p[j]<=lim;j++) {
			tab[i*p[j]] = 1;
			if(!(i % p[j])) break;
		}
	}
}
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}
int inv(int x) {return qpow(x, mod-2);}
void dfs(int u, int f) {
	for(auto i : e[u]) {
		int v = i.j, x = i.x, y = i.y;
		if(v == f) continue;
		val[v] = 1LL * val[u] * y % mod * inv(x) % mod;
		for(auto j : divisor[y]) {
			int d = get<0>(j), cnt = get<1>(j);
			buc[d] += cnt;
		}
		for(auto j : divisor[x]) {
			int d = get<0>(j), cnt = get<1>(j);
			buc[d] -= cnt;
			chkmax(mx[d], -buc[d]);
		}
		dfs(v, u);
		for(auto j : divisor[x]) {
			int d = get<0>(j), cnt = get<1>(j);
			buc[d] += cnt;
		}
		for(auto j : divisor[y]) {
			int d = get<0>(j), cnt = get<1>(j);
			buc[d] -= cnt;
		}
	}
}

int main() {
	sieve(200000);
	rep(i, 1, 200000) {
		int j = i;
		for(int id=1;id<=tot&&p[id]*p[id]<=j;id++) {
			int d = p[id], cnt = 0;
			for(;!(j%d);++cnt,j/=d);
			if(cnt) divisor[i].push_back(make_tuple(d, cnt));
		}
		if(j > 1) divisor[i].push_back(make_tuple(j, 1));
	}
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n-1) {
			scanf("%d%d%d%d", &a[i].i, &a[i].j, &a[i].x, &a[i].y);
			e[a[i].i].push_back(Fact(a[i].i, a[i].j, a[i].x, a[i].y));
			e[a[i].j].push_back(Fact(a[i].j, a[i].i, a[i].y, a[i].x));
		}
		val[1] = 1;
		dfs(1, 0);
		int lcm = 1, ans = 0;
		for(int i=1;i<=tot&&p[i]<=n;i++) {
			int d = p[i];
			if(mx[d]) {
				lcm = 1LL * lcm * qpow(d, mx[d]) % mod;
			}
		}
		rep(i, 1, n) ans = (ans + val[i]) % mod;
		ans = 1LL * ans * lcm % mod;
		printf("%d\n", ans);
		rep(i, 1, n) {
			buc[i] = mx[i] = val[i] = 0;
			e[i].clear();
		}
	}
	return 0;
}