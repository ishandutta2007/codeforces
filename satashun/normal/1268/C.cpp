#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int MN = 200010;

// 1-indexed, [1, n]
template<class T>
class BIT {
	T bit[MN];
	int n;

public:
	BIT() {
		n = MN;
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

BIT<int> T, R;

int main() {
	int n; cin >> n;
	V<int> p(n);

	rep(i, n) {
		cin >> p[i];
		--p[i];
	}

	V<pii> vec(n);
	rep(i, n) vec[i] = mp(p[i], i);

	sort(ALL(vec));

	V<ll> ans(n);
	ll rr = 0;

	set<int> sl, sr;
	ll mv = 0;
	rep(i, n) R.add(i, 1);

	rep(i, n) {			
		int p = vec[i].se;
		int num = i - T.sum(p);
		rr += num;
		ans[i] = rr;

		int k = min(num, i - num);
		mv -= k;

		R.add(p, -1);

		if (i > 0) {
			if (sl.size() == sr.size()) {
				int ml = *sl.rbegin(), mr = *sr.begin();
				if (p < ml) {
					mv += R.sum(ml) - R.sum(p);
				} else if (p > mr) {
					mv += R.sum(p) - R.sum(mr);
				}
			} else {
				int m;
				if (sl.size() > sr.size()) {
					m = *sl.rbegin();
				} else {
					m = *sr.begin();
				}
				if (p < m) {
					mv += R.sum(m) - R.sum(p);
				} else {
					mv += R.sum(p) - R.sum(m);
				}
			}
		}

		if (sr.size() && *sr.begin() < p) {
			sr.insert(p);
		} else {
			sl.insert(p);
		}

		if (sl.size() > sr.size() + 1) {
			int x = *sl.rbegin();
			sl.erase(x);
			sr.insert(x);
		} else if (sl.size() + 1 < sr.size()) {
			int x = *sr.begin();
			sr.erase(x);
			sl.insert(x);			
		}
		ans[i] += mv;

		T.add(p, 1);
	}


	rep(i, n) printf("%lld%c", ans[i], i == n-1 ? '\n' : ' ');

	return 0;
}