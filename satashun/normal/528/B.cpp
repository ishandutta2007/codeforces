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

const int SZ = 1 << 19;

struct segtree_max {
    vector<int> dat;

    void init() {
	dat.resize(SZ * 2);
	rep(i, SZ * 2) dat[i] = 0;
    }

    void update(int pos, int x) {
	pos += SZ - 1;
	dat[pos] = x;

	while (pos > 0) {
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
	if (b <= l || r <= a) return 0;
	if (a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} seg;

int n;
int dp[200010];
vi xs;
pii pt[200010];
int ret;

int main() {
    cin >> n;

    rep(i, n) {
	cin >> pt[i].fi >> pt[i].se;
	xs.pb(pt[i].fi + pt[i].se);
    }

    sort(pt, pt + n);
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());

    seg.init();

    rep(i, n) {
	int p = upper_bound(ALL(xs), pt[i].fi - pt[i].se) - xs.begin();
	int val = seg.get(0, p);
	dp[i] = val + 1;

	seg.update(lower_bound(ALL(xs), pt[i].fi + pt[i].se) - xs.begin(), dp[i]);
	ret = max(ret, dp[i]);
    }

    cout << ret << endl;
    
    return 0;
}