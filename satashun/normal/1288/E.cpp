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

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

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

template<class T>
struct BIT {
	int n;
	vector<T> bit;

	BIT(int _n = 0) : n(_n), bit(n + 1) {}

	//sum of [0, i), 0 <= i <= n
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//0 <= i < n
	void add(int i, T x) {
		++i;
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	//[l, r) 0 <= l < r < n
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

int main() {
	int n, m; cin >> n >> m;
	V<int> a(m);

	BIT<int> T(n + m + 10);
	rep(i, m) {
		cin >> a[i];
		--a[i];
	}

	V<int> mini(n), maxi(n);
	rep(i, n) mini[i] = maxi[i] = i;

	set<pii> st;
	V<int> pos(n);

	rep(i, n) {
		pos[i] = i + m;
		T.add(i + m, 1);
		st.insert(mp(pos[i], i));
	}

	rep(i, m) {
		int x = a[i];
		mini[x] = 0;

		int curpos = pos[x];
		st.erase(mp(curpos, x));

		T.add(curpos, -1);
		pos[x] = m-1-i;
		int r = T.sum(curpos);
		dump(r);
		chmax(maxi[x], r);
		st.insert(mp(m-1-i, x));
		T.add(pos[x], 1);
	}

	int now = 0;
	for (auto &x : st) {
		chmax(maxi[x.se], now++);
	}

	rep(i, n) printf("%d %d\n", mini[i] + 1, maxi[i] + 1);

	return 0;
}