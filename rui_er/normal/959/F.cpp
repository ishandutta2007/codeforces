//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7; 

int n, m, a[N], pw2[N], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Query {
	int l, x, id;
	Query(int a=0, int b=0, int c=0) : l(a), x(b), id(c) {}
	~Query() {}
}q[N];
struct LinearBasis {
	int p[21], tot;
	LinearBasis() : tot(0) {memset(p, 0, sizeof(p));}
	~LinearBasis() {}
	void insert(int x) {
		per(i, 20, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {
				p[i] = x;
				++tot;
				return;
			}
			x ^= p[i];
		}
	}
	bool valid(int x) {
		per(i, 20, 0) {
			if((x >> i) & 1) {
				if(!p[i]) return 0;
				x ^= p[i];
			}
		}
		return 1;
	}
}LB;

int main() {
	pw2[0] = 1;
	rep(i, 1, 100000) pw2[i] = 2LL * pw2[i-1] % mod;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, m) {
		scanf("%d%d", &q[i].l, &q[i].x);
		q[i].id = i;
	}
	sort(q+1, q+1+m, [](const Query& a, const Query& b) -> bool {
		return a.l < b.l;
	});
	int now = 0;
	rep(i, 1, m) {
		while(now < q[i].l) LB.insert(a[++now]);
		ans[q[i].id] = LB.valid(q[i].x) ? pw2[now-LB.tot] : 0;
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
    return 0;
}