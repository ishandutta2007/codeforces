// Problem: CF86D Powerful array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF86D
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, W = 1e6+5;

ll n, m, a[N], pos[N], L[N], R[N], sz, tot, buc[W], ans[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Query {
	ll l, r, id;
	Query(ll a=0, ll b=0, ll c=0) : l(a), r(b), id(c) {}
	~Query() {}
	friend bool operator < (const Query& a, const Query& b) {
		if(pos[a.l] == pos[b.l]) return a.r < b.r;
		return a.l < b.l;
	}
}q[N];
void initBlock() {
	sz = sqrt(n);
	while(++tot) {
		L[tot] = R[tot-1] + 1;
		R[tot] = min(sz * tot, n);
		rep(i, L[tot], R[tot]) pos[i] = tot;
		if(R[tot] == n) break;
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) scanf("%lld%lld", &q[i].l, &q[i].r), q[i].id = i;
	initBlock();
	sort(q+1, q+1+m);
	ll l = 1, r = 0, now = 0;
	rep(i, 1, m) {
		while(q[i].l < l) {
			--l;
			now -= buc[a[l]] * buc[a[l]] * a[l];
			++buc[a[l]];
			now += buc[a[l]] * buc[a[l]] * a[l];
		}
		while(q[i].r > r) {
			++r;
			now -= buc[a[r]] * buc[a[r]] * a[r];
			++buc[a[r]];
			now += buc[a[r]] * buc[a[r]] * a[r];
		}
		while(q[i].l > l) {
			now -= buc[a[l]] * buc[a[l]] * a[l];
			--buc[a[l]];
			now += buc[a[l]] * buc[a[l]] * a[l];
			++l;
		}
		while(q[i].r < r) {
			now -= buc[a[r]] * buc[a[r]] * a[r];
			--buc[a[r]];
			now += buc[a[r]] * buc[a[r]] * a[r];
			--r;
		}
		ans[q[i].id] = now;
	}
	rep(i, 1, m) printf("%lld\n", ans[i]);
	return 0;
}