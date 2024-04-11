//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, a[N], c[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct LinearBasis {
	int p[31];
	LinearBasis() {memset(p, 0, sizeof(p));}
	~LinearBasis() {}
	void insert(int x) {
		per(i, 30, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {p[i] = x; return;}
			x ^= p[i];
		}
	}
	int size() {
		int ans = 0;
		rep(i, 0, 30) ans += !!p[i];
		return ans;
	}
	int count() {
		return 1 << size();
	}
	friend LinearBasis operator + (const LinearBasis& L, const LinearBasis& R) {
		LinearBasis ans = L;
		rep(i, 0, 30) ans.insert(R.p[i]);
		return ans;
	}
};
struct Segtree {
	LinearBasis w[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		w[u] = w[lc(u)] + w[rc(u)];
	}
	void build(int u, int l, int r) {
		if(l == r) {
			w[u].insert(a[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, int pos, int k) {
		if(l == r) {
			w[u] = LinearBasis();
			w[u].insert(a[l]^=k);
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) modify(lc(u), l, mid, pos, k);
		else modify(rc(u), mid+1, r, pos, k);
		pushup(u);
	}
	LinearBasis query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return w[u];
		int mid = (l + r) >> 1;
		LinearBasis ans;
		if(ql <= mid) ans = ans + query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans = ans + query(rc(u), mid+1, r, ql, qr);
		return ans;
	}
	#undef lc
	#undef rc
}sgt;
int lowbit(int x) {return x&(-x);}
void upd(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] ^= k;}
int ask(int x) {int ans = 0; for(;x;x-=lowbit(x)) ans ^= c[x]; return ans;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	per(i, n, 2) a[i] ^= a[i-1];
	rep(i, 1, n) upd(i, a[i]);
	sgt.build(1, 1, n);
	while(m --> 0) {
		int op, l, r, val;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			scanf("%d", &val);
			upd(l, val);
			sgt.modify(1, 1, n, l, val);
			if(r < n) {
				upd(r+1, val);
				sgt.modify(1, 1, n, r+1, val);
			}
		}
		else {
			int k = ask(l);
			LinearBasis ans = sgt.query(1, 1, n, l+1, r);
			ans.insert(k);
			printf("%d\n", ans.count());
		}
	}
    return 0;
}