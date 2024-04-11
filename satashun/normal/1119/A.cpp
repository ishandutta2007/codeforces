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
	int n; scanf("%d", &n);
	vi c(n); rep(i, n) scanf("%d", &c[i]);

	vector<pii> cand;

	for (int i = n-1; i >= 0; --i) {
		if (cand.size() == 2) break;

		bool f = 1;
		for (pii p : cand) {
			if (p.fi == c[i]) {
				f = 0;
			}
		}
		if (f) {
			cand.eb(c[i], i);
		}
	}

	int ans = 0;
	rep(i, n) {
		int m = -1;
		for (pii p : cand) {
			if (p.fi != c[i]) {
				m = max(m, p.se);
			}
		}
		ans = max(ans, m - i);
	}
	printf("%d\n", ans);

	return 0;
}