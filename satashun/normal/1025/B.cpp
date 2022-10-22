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

V<int> dv(int x) {
	V<int> res;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			res.pb(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x != 1) res.pb(x);
	return res;
}

int main() {
	int n; cin >> n;
	V<pii> vec(n);

	rep(i, n) {
		int a, b;
		cin >> a >> b;
		vec[i] = mp(a, b);
	}

	V<int> cand[2] = {dv(vec[0].fi), dv(vec[0].se)};
	for (auto v : cand) {
		for (auto x : v) {
			bool ok = 1;
			rep(i, n) if (vec[i].fi % x != 0 && vec[i].se % x != 0) {
				ok = 0;
			}
			if (ok) {
				cout << x << endl;
				return 0;
			}
		}
	}
	puts("-1");

	return 0;
}