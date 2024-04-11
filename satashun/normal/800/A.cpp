#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
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

int main() {
	int n, p; cin >> n >> p;
	V<int> a(n), b(n);

	rep(i, n) {
		cin >> a[i] >> b[i];
	}

	ll sum = 0;
	rep(i, n) {
		sum += a[i];
	}
	if (sum <= p) {
		puts("-1");
		return 0;
	}

	auto ok = [&](double t) {
		double s = 0.0;
		rep(i, n) {
			s += max(t * a[i] - b[i], 0.0) / p;
		}
		return s <= t;
	};

	double lo = 0.0, hi = 1e15;
	if (ok(hi)) {
		puts("-1");
		return 0;
	}

	rep(tt, 100) {
		double m = (lo + hi) / 2;
		if (ok(m)) {
			lo = m;
		} else {
			hi = m;
		}
	}

	printf("%.5f\n", hi);

	return 0;
}