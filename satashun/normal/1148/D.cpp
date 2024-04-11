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

int main() {
	int n; cin >> n;
	V<int> a(n), b(n);
	V<int> v1, v2;

	rep(i, n) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i]) {
			v1.pb(i);
		} else {
			v2.pb(i);
		}
	}

	{
		V<pair<pii, int>> vec;
		for (int i : v1) {
			vec.eb(mp(a[i], b[i]), i);
		}
		sort(ALL(vec));
		V<int> vl;
		for (auto p : vec) {
			vl.pb(p.se);
		}
		v1 = vl;
	}

	{
		V<pair<pii, int>> vec;
		for (int i : v2) {
			vec.eb(mp(b[i], a[i]), i);
		}
		sort(ALL(vec));
		reverse(ALL(vec));
		V<int> vl;
		for (auto p : vec) {
			vl.pb(p.se);
		}
		v2 = vl;
	}

	V<int> ans;
	if (v1.size() > v2.size()) {
		ans = v1;
	} else {
		ans = v2;
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
	}

	return 0;
}