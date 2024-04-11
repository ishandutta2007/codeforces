#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

const int N = 100010;

template<class T>
class BIT {
    T bit[N];
    int n;

    public:
    BIT() {
	n = N;
	memset(bit, 0, sizeof(bit));
    }

    T sum(int i) {
	T s = 0;
	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}
	return s;
    }

    void add(int i, T x) {
	while (i <= n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

struct segtree{
    int sz;
    int lazy[1 << 18];
    pii dat[1 << 18]; 
    int cnt[1 << 18];

    void init(int n, int *a){
	memset(lazy, 0, sizeof(lazy));
	for(sz = 1; sz < n; sz *= 2);
	for(int i = sz - 1; i < sz * 2 - 1; ++i){
	    dat[i] = mp(a[i - sz + 1], i - sz + 1);
	    cnt[i] = 1;
	}
	for(int i = sz - 2; i >= 0; --i){ 
	    dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);

	    cnt[i] = 0;
	    if(dat[i].fi == dat[i * 2 + 1].fi) cnt[i] += cnt[i * 2 + 1];
	    if(dat[i].fi == dat[i * 2 + 2].fi) cnt[i] += cnt[i * 2 + 2];	    
	}
    }

    inline void spread(int k){
	if(lazy[k] == 0) return ;
	dat[k].fi += lazy[k];
	if(k < sz - 1){
	    lazy[k * 2 + 1] += lazy[k];
	    lazy[k * 2 + 2] += lazy[k];
	}
	lazy[k] = 0;
    }

    inline void upd(int k){
	cnt[k] = 0;
	dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	if(dat[k * 2 + 1].fi == dat[k].fi) cnt[k] += cnt[k * 2 + 1];
	if(dat[k * 2 + 2].fi == dat[k].fi) cnt[k] += cnt[k * 2 + 2];
    }
    
    void add(int a, int b, int x){ add(a, b, x, 0, 0, sz); }

    void add(int a, int b, int x, int k, int l, int r){
	spread(k);
	if(r <= a || b <= l) return ;
	if(a <= l && r <= b){ lazy[k] += x; spread(k); return ; }
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	upd(k);
    }
    
    pair<pii, int> query(int a, int b){ return query(a, b, 0, 0, sz); }

    pair<pii, int> query(int a, int b, int k, int l, int r){
	spread(k);
	if(r <= a || b <= l) return mp(mp(INT_MAX, INT_MAX), 0);
	if(a <= l && r <= b) return mp(dat[k], cnt[k]);

	pair<pii, int> lch = query(a, b, k * 2 + 1, l, (l + r) / 2),
	    rch = query(a, b, k * 2 + 2, (l + r) / 2, r);

	pii ret = min(lch.fi, rch.fi);
	int s = 0;
	if(ret.fi == lch.fi.fi) s += lch.se;
	if(ret.fi == rch.fi.fi) s += rch.se;
	return mp(ret, s);
    }
}seg;

int n, m;
int diff[1 << 17];
int a[1 << 17];
vector<int> vec[10];
int nxt[1000010];
BIT<int> T;

int main(){
    vec[0].pb(4); vec[0].pb(7);
    rep(i, 4) for(int &x : vec[i]){
	vec[i+1].pb(x * 10 + 4);
	vec[i+1].pb(x * 10 + 7);
    }

    rep(i, 44450) nxt[i] = INT_MAX;
    rep(i, 5) for(int &x : vec[i]) nxt[x] = x;   
    for(int i = 44444; i > 0; --i) nxt[i] = min(nxt[i+1], nxt[i]);

    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) diff[i] = nxt[a[i]] - a[i];
    seg.init(n, diff);

    while(m--){
	int l, r;
	char c[10]; string s;
	scanf("%s %d %d", c, &l, &r);
	s = c; --l;

	if(s == "count"){
	    pair<pii, int> res = seg.query(l, r);
	    //cout << res.fi.fi << endl;
	    int ret = 0;
	    if(res.fi.fi == 0) ret = res.se; 
	    printf("%d\n", ret);
	}else{
	    int x; scanf("%d", &x);
	    while(true){
		pair<pii, int> res = seg.query(l, r);
		if(res.fi.fi >= x) break;

		int p = res.fi.se;
		int cur = T.sum(p + 1) + a[p];
		//cout << "cur " << cur << endl;
		int nn = nxt[cur + x];
		//cout << "nn " << nn << endl;		
		seg.add(p, p + 1, (nn - cur) - res.fi.fi);
	    }
	    seg.add(l, r, -x);
	    T.add(l + 1, x);
	    T.add(r + 1, -x);
	}
    }
    return 0;
}