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
	int n; cin >> n;
	vector<ll> s(n); rep(i, n) cin >> s[i];
	sort(ALL(s));

	vector<pair<ll, int>> dif(n-1);

	rep(i, n-1) {
		dif[i] = mp(s[i+1] - s[i], i);
	}

	sort(ALL(dif));

	int q; cin >> q;

	vector<ll> l(q), r(q), ans(q);
	vector<pair<ll, int>> vec(q);

	rep(i, q) {
		cin >> l[i] >> r[i];
		vec[i] = mp(r[i] - l[i], i);
	}
	sort(ALL(vec));

	int piv = 0;
	ll cur = 0;
	int cmp = n;

	for (const auto &p : vec) {
		ll gap = p.fi, id = p.se;
		while (piv < n-1 && dif[piv].fi <= gap) {
			int a = dif[piv].se, b = a + 1;
			cur += dif[piv].fi;
			--cmp;
			++piv;
		}
		ans[id] = cur + (r[id] - l[id] + 1) * cmp;
	}

	rep(i, q) cout << ans[i] << (i == q-1 ? '\n' : ' ');

	return 0;
}