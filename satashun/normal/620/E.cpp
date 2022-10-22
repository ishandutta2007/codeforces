#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 400010;
const int MM = 400010;
const int sz = 1 << 19;

struct NODE{
	int lazy;
	ll mask;
	NODE() { lazy = -1; mask = 0; }
};

struct segtree{
	NODE dat[sz * 2];

	void init() {
		rep(i, sz * 2) {
			dat[i].lazy = -1;
			dat[i].mask = 0;
		}
	}

	inline void lazy_eval(int k, int a, int b) {
		if (dat[k].lazy != -1) {
			dat[k].mask = (1LL << dat[k].lazy);
			if(k < sz - 1){
				dat[k * 2 + 1].lazy = dat[k].lazy;
				dat[k * 2 + 2].lazy = dat[k].lazy;
			}
			dat[k].lazy = -1;
		}
	}

	inline void update_node(int k){ dat[k].mask = dat[k * 2 + 1].mask | dat[k * 2 + 2].mask; }

	void change(int a, int b, int x, int k = 0, int l = 0, int r = sz) {
		lazy_eval(k, l, r);
		if (r <= a || b <= l) return ;
		if (a <= l && r <= b) {
			dat[k].lazy = x;
			lazy_eval(k, l, r);
			return ;
		}
		change(a, b, x, k * 2 + 1, l, (l + r) / 2);
		change(a, b, x, k * 2 + 2, (l + r) / 2, r);
		update_node(k);
	}

	ll get(int a, int b, int k = 0, int l = 0, int r = sz) {
		lazy_eval(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return dat[k].mask;
		ll ret = get(a, b, k * 2 + 1, l, (l + r) / 2) | get(a, b, k * 2 + 2, (l + r) / 2, r);
		update_node(k);
		return ret;
	}
} seg;

int n, m;
int in[MN], out[MN];
int col[MN];
vi g[MN];

void dfs(int v, int p, int &k) {
	in[v] = k++;
	for (int to : g[v]) if (to != p) {
		dfs(to, v, k);
	}
	out[v] = k;
	seg.change(in[v], in[v] + 1, col[v]);
}

int main() {
	seg.init();

	scanf("%d %d", &n, &m);

	rep(i, n) {
		scanf("%d", &col[i]);
		--col[i];
	}

	rep(i, n-1) {
		int a, b;
		scanf("%d %d", &a, &b); --a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	int now = 0;
	dfs(0, -1, now);

	rep(i, m) {
		int tp, v, c;
		scanf("%d %d", &tp, &v);
		--v;
		if (tp == 1) {
			scanf("%d", &c); --c;
			seg.change(in[v], out[v], c);
		} else {
			ll ret = seg.get(in[v], out[v]);
			printf("%d\n", __builtin_popcountll(ret));
		}
	}
	return 0;
}