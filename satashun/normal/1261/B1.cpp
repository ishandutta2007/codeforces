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

int main() {
	BIT<int> T;

	int n; scanf("%d", &n);
	V<int> a(n);
	//V<int> xs;
	rep(i, n) scanf("%d", &a[i]);
	V<pii> vec(n);
	rep(i, n) {
		vec[i] = mp(a[i], -i);
		//xs.pb(a[i]);
	}

	sort(ALL(vec));
	reverse(ALL(vec));
	/*
	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());*/

	int m;
	scanf("%d", &m);
	V<pii> query(m);

	VV<pii> vq(n + 1);
	rep(i, m) {
		int k, p;
		scanf("%d %d", &k, &p);
		query[i] = mp(k, p);
		vq[k].eb(i, p);
	}

	V<int> ans(m);
	set<int> st;

	rep(i, n) {
		int id = -vec[i].se;
		T.add(id, 1);
		st.insert(id);

		for (auto pr : vq[i+1]) {
			int lo = 0, hi = n;
			while (hi - lo > 1) {
				int mid = (lo + hi) / 2;
				if (T.sum(mid) <= pr.se) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			auto it = st.upper_bound(lo);
			ans[pr.fi] = a[*(--it)];
		}
	}
	rep(i, m) {
		printf("%d\n", ans[i]);
	}
	return 0;
}