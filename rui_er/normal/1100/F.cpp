//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5; 

int n, a[N], m, ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Query {
	int L, R, id;
	Query(int a=0, int b=0, int c=0) : L(a), R(b), id(c) {}
	~Query() {}
}q[N];
struct LinearBasis {
	int p[21], tms[21]; // timestamp
	LinearBasis() {
		memset(p, 0, sizeof(p));
		memset(tms, 0, sizeof(tms));
	}
	~LinearBasis() {}
	void insert(int x, int tm) {
		per(i, 20, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {
				p[i] = x;
				tms[i] = tm;
				return;
			}
			if(tm > tms[i]) {
				swap(x, p[i]);
				swap(tm, tms[i]);
			}
			x ^= p[i];
		}
	}
	int qmax(int tm) {
		int ans = 0;
		per(i, 20, 0) {
			if(p[i] && tms[i] >= tm) {
				chkmax(ans, ans^p[i]);
			}
		}
		return ans;
	}
}LB;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	rep(i, 1, m) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].id = i;
	}
	sort(q+1, q+1+m, [](const Query& a, const Query& b) -> bool {
		return a.R < b.R;
	});
	int now = 0;
	rep(i, 1, m) {
		while(now < q[i].R) {
			++now;
			LB.insert(a[now], now);
		}
		ans[q[i].id] = LB.qmax(q[i].L);
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
    return 0;
}