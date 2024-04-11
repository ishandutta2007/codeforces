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

const int N = 500010;

// 1-indexed, [1, n]
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
	++i;

	T s = 0;
	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}
	return s;
    }

    void add(int i, T x) {
	++i;
	while (i < n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

int n;
int l[200010], r[200010];
pair<pii, int> pr[200010];
vi xs;
int ans[200010];
BIT<int> T;

bool cmp(const pair<pii, int> &a, const pair<pii, int> &b) 
{
    return a.fi.se < b.fi.se;
}

int main() {
    cin >> n;

    rep(i, n) {
	cin >> l[i] >> r[i];
	xs.pb(l[i]);
	xs.pb(r[i]);
    }

    sort(ALL(xs));

    rep(i, n) {
	l[i] = lower_bound(ALL(xs), l[i]) - xs.begin();
	r[i] = lower_bound(ALL(xs), r[i]) - xs.begin();
	pr[i] = mp(mp(l[i], r[i]), i);
    }

    sort(pr, pr + n, cmp);

    rep(i, n) {
	int l = pr[i].fi.fi, r = pr[i].fi.se;
	int id = pr[i].se;

	ans[id] = i - T.sum(l);
	T.add(l, 1);
    }

    rep(i, n) cout << ans[i] << endl;

    return 0;
}