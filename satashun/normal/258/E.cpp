#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

struct segtree{
    int *lazy, *mi, *cnt;
    int sz;

    segtree(int n){
	for(sz = 1; sz < n; sz *= 2); 
	lazy = new int[sz * 2 - 1];
	mi = new int[sz * 2 - 1];
	cnt = new int[sz * 2 - 1];
    }

    void init(){ init(0, 0, sz); }
    void add(int a, int b, int x){ add(a, b, x, 0, 0, sz); }
    pii query(int a, int b){ return query(a, b, 0, 0, sz); }

    void init(int k, int l, int r){
	lazy[k] = mi[k] = 0;
	cnt[k] = r - l;
	if(k < sz - 1){
	    init(k * 2 + 1, l, (l + r) / 2);
	    init(k * 2 + 2, (l + r) / 2, r);
	}
    }

    inline void spread(int k){
	if(lazy[k] == 0) return ;
	mi[k] += lazy[k];
	if(k < sz - 1){
	    lazy[k * 2 + 1] += lazy[k];
	    lazy[k * 2 + 2] += lazy[k];
	}
	lazy[k] = 0;
    }

    inline void upd(int k){
	cnt[k] = 0;
	mi[k] = min(mi[k * 2 + 1], mi[k * 2 + 2]);
	if(mi[k * 2 + 1] == mi[k]) cnt[k] += cnt[k * 2 + 1];
	if(mi[k * 2 + 2] == mi[k]) cnt[k] += cnt[k * 2 + 2];
    }

    void add(int a, int b, int x, int k, int l, int r){
	spread(k);
	if(r <= a || b <= l) return ;
	if(a <= l && r <= b){ lazy[k] += x; spread(k); return ; }
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	upd(k);
    }

    pii query(int a, int b, int k, int l, int r){
	spread(k);
	if(r <= a || b <= l) return mp(0, INT_MAX);
	if(a <= l && r <= b) return mp(cnt[k], mi[k]);
	pii lc = query(a, b, k * 2 + 1, l, (l + r) / 2);
	pii rc = query(a, b, k * 2 + 2, (l + r) / 2, r);

	pii ret = mp(0, INT_MAX);
	if(lc.se <= rc.se) ret = lc;
	if(rc.se <= lc.se){
	    ret.se = rc.se;
	    ret.fi += rc.fi;
	}
	return ret;
    }
};

int n, m;
segtree *t;
vector<int> g[100010];
vector<int> op[100010];
int in[100010], out[100010];
int ans[100010];
int now;

inline void tour(int v, int p){
    in[v] = now++;
    for(int &to : g[v]) if(to != p) tour(to, v);
    out[v] = now;
}

void calc(int v, int p){
    bool f = false;

    for(int &x : op[v]){
	t->add(in[x], out[x], 1);
	if(!f){
	    f = true;
	    t->add(in[v], out[v], 1);
	}
    }

    pii ret = t->query(0, n);
    if(ret.se > 0) ans[v] = n;
    else ans[v] = n - ret.fi;
    if(ans[v]) --ans[v];

    for(int &to : g[v]) if(to != p) calc(to, v);

    for(int &x : op[v])
	t->add(in[x], out[x], -1);

    if(f) t->add(in[v], out[v], -1);
}

int main(){
    scanf("%d %d", &n, &m);

    rep(i, n - 1){
	int a, b;
	scanf("%d %d", &a, &b); --a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    rep(i, m){
	int a, b;
	scanf("%d %d", &a, &b); --a; --b;
	op[a].pb(b); op[b].pb(a);
    }

    tour(0, -1);
    t = new segtree(n);
    t->init();
    calc(0, -1);
    rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}