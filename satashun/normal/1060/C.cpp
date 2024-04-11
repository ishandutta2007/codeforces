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
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

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
	int n, m; cin >> n >> m;
	vi a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	int x; cin >> x;

	int ans = 0;

	vector<pii> vec;

	rep(i, n) {
		int s = 0;
		for (int j = i; j < n; ++j) {
			s += a[j];
			vec.eb(s, j - i + 1);
		}
	}
	sort(ALL(vec));

	vi ac(vec.size() + 1);
	ac[0] = 0;
	rep(i, vec.size()) {
		ac[i+1] = max(ac[i], vec[i].se);
	}

	rep(i, m) {
		int s = 0;
		for (int j = i; j < m; ++j) {
			s += b[j];
			int a = x / s;
			int u = upper_bound(ALL(vec), mp(a, 10000)) - vec.begin();
			ans = max(ans, (j - i + 1) * ac[u]);
		}
	}

	cout << ans << endl;

	return 0;
}