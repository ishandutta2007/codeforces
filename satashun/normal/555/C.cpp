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

struct segtree{
    int seg[1 << 19], lazy[1 << 19];

    segtree() {
	memset(seg, 0, sizeof(seg));
	memset(lazy, 0, sizeof(lazy));
    }

    inline void eval(int k)
    {
	seg[k] = max(seg[k], lazy[k]);
	if (k < (1 << 18) - 1) {
	    lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
	    lazy[k * 2 + 2] = max(lazy[k * 2 + 2], lazy[k]);
	}
	lazy[k] = 0;
    }

    inline void updateNode(int k)
    {
	seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
    }

    inline void changeMax(int a, int b, int x, int k = 0, int l = 0, int r = 1 << 18)
    {
	eval(k);
	if (b <= l || r <= a) return;

	if (a <= l && r <= b){
	    lazy[k] = max(lazy[k], x);
	    eval(k);
	    return;
	}

	changeMax(a, b, x, k * 2 + 1, l, l + r >> 1);
	changeMax(a, b, x, k * 2 + 2, l + r >> 1, r);
	updateNode(k);
    }

    inline int get(int a, int k = 0, int l = 0, int r = 1 << 18)
    {	
	eval(k);
	if (a + 1 <= l || r <= a) return (-1);

	if (a <= l && r <= a + 1) {
	    return (seg[k]);
	}

	int lch = get(a, k * 2 + 1, l, l + r >> 1);
	int rch = get(a, k * 2 + 2, l + r >> 1, r);
	updateNode(k);
	return (max(lch, rch));
    }
} segU, segL;

int n, q;
vector<int> xs;
//vector<int> xs;
pii query[200010];

inline int pos(vector<int>& vec, int x)
{
    return lower_bound(ALL(vec), x) - vec.begin();
}

int main() {
    scanf("%d %d", &n, &q);
    xs.pb(0); xs.pb(n);
    //ys.pb(0); ys.pb(n);

    rep(i, q) {
	int x, y; char c;
	scanf("%d %d %c", &x, &y, &c);
	query[i] = mp(x, (c == 'U'));
	xs.pb(x); //ys.pb(y);
    }

    sort(ALL(xs));
    //sort(ALL(ys));
    xs.erase(unique(ALL(xs)), xs.end());
    //ys.erase(unique(ALL(ys)), ys.end());

    rep(i, q) {
	if (query[i].se) { // type..U
	    int x = query[i].fi;
	    int p = pos(xs, x);
	    int L = n + 1 - x - segU.get(p);
	    printf("%d\n", L);

	    if (!L) continue;

	    int l = pos(xs, x);
	    int r = pos(xs, x + 1);

	    segU.changeMax(l, r, n + 1 - x);

	    l = pos(xs, x);
	    r = pos(xs, x + L);
	    if (l == r) continue;
	    segL.changeMax(l, r, x);

	} else {
	    int x = query[i].fi;
	    int p = pos(xs, x);
	    int L = x - segL.get(p);
	    printf("%d\n", L);

	    if (!L) continue;

	    int l = pos(xs, x);
	    int r = pos(xs, x + 1);

	    segL.changeMax(l, r, x);

	    l = pos(xs, x - L + 1);
	    r = pos(xs, x + 1);
	    if (l == r) continue;
	    segU.changeMax(l, r, n + 1 - x);
	}
    }

    return 0;
}