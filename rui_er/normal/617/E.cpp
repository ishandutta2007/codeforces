//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, K = 3e6+5;

ll n, m, k, a[N], s[N], L[N], R[N], pos[N], sz, tot, buc[K], qwq, ans[N];
struct Query {
	ll id, l, r, len;
	Query(ll a=0, ll b=0, ll c=0) : id(a), l(b), r(c), len(c-b+1) {}
	~Query() {}
	friend bool operator < (const Query &a, const Query &b) {
		if(pos[a.l] == pos[b.l]) return a.r < b.r;
		return pos[a.l] < pos[b.l];
	}
}ask[N];
void initBlock() {
	sz = sqrt(n);
	while(++tot) {
		L[tot] = R[tot-1] + 1;
		R[tot] = min(tot*sz, n);
		rep(i, L[tot], R[tot]) pos[i] = tot;
		if(R[tot] == n) break;
	}
}
void ins(ll x) {qwq += buc[s[x]^k]; ++buc[s[x]];}
void del(ll x) {--buc[s[x]]; qwq -= buc[s[x]^k];}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	initBlock();
	rep(i, 1, n) scanf("%lld", &a[i]), s[i] = s[i-1] ^ a[i];
	rep(i, 1, m) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ask[i] = Query(i, l-1, r);
	}
	sort(ask+1, ask+1+m);
	ll l = 1, r = 0;
	rep(i, 1, m) {
		while(l > ask[i].l) ins(--l);
		while(r < ask[i].r) ins(++r);
		while(l < ask[i].l) del(l++);
		while(r > ask[i].r) del(r--);
		ans[ask[i].id] = qwq;
	}
	rep(i, 1, m) printf("%lld\n", ans[i]);
    return 0;
}