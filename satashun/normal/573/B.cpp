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

const int SZ = 1 << 18;

struct segtree {
    vector<int> dat;

    void init() {
	dat.resize(SZ * 2);
	rep(i, SZ * 2) dat[i] = INT_MAX;
    }

    void update(int pos, int x) {
	pos += SZ - 1;
	dat[pos] = x;

	while (pos > 0) {
	    pos = (pos - 1) / 2;
	    dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
	if (b <= l || r <= a) return INT_MAX;
	if (a <= l && r <= b) return dat[k];
	return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} segl, segr;

int n;
int h[100010];
int d[100010];
int ret;

int main() {
    cin >> n;
    segl.init();
    segr.init();

    rep(i, n) {
	d[i] = min(i, n - 1 - i) + 1;

	cin >> h[i];
	segl.update(i, h[i] - i);
	segr.update(i, h[i] + i);
    }

    rep(i, n) {
	int l = segl.get(0, i + 1);
	int r = segr.get(i, n);
	d[i] = min(d[i], l + i);
	d[i] = min(d[i], r - i);
	ret = max(ret, d[i]);
    }

    cout << ret << endl;

    return 0;
}