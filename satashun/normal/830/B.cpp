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
	vector<pii> dat;

	void init() {
		dat.resize(SZ * 2);
		rep(i, SZ * 2) dat[i] = mp(INT_MAX, 0);
	}

	void update(int pos, pii x) {
		pos += SZ - 1;
		dat[pos] = x;

		while (pos > 0) {
			pos = (pos - 1) / 2;
			dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
		}
	}

	pii get(int a, int b, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return mp(INT_MAX, -1);
		if (a <= l && r <= b) return dat[k];
		return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
	}
} seg;

const int N = 100010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[N];
	int n;

public:
	BIT() {
		n = N + 10;
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
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int n;
int a[100010];
ll ret;
BIT<int> T;

int main() {
	cin >> n;
	seg.init();

	rep(i, n) {
		cin >> a[i];
		seg.update(i, mp(a[i], i));
		T.add(i, 1);
	}

	int p = 0;

	rep(i, n) {
		pii r = seg.get(p, n);
		pii l = seg.get(0, p);

		int nx;
		ll ad = 0;
		if (r.fi > l.fi) {
			nx = l.se;
			ad = T.sum(n) - T.sum(p) + T.sum(nx);
		} else {
			nx = r.se;
			ad = T.sum(nx) - T.sum(p);
		}

		ret += ad;

		T.add(nx, -1);

		seg.update(nx, mp(INT_MAX, i));
		p = nx;
	}

	cout << ret + 1 << endl;

	return 0;
}