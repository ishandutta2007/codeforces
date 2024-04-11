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
	V<int> p(n), pos(n);
	rep(i, n) {
		cin >> p[i];
		--p[i];
		pos[p[i]] = i;
	}

	V<pii> ans;

	rep(i, n) {
		if (p[i] == i) continue;
		int to = pos[i];
		if (abs(to - i) >= n / 2) {
			ans.eb(i, to);
		} else if (abs(n - 1 - to) >= n / 2) {
			ans.eb(i, n - 1);
			ans.eb(n - 1, to);
			ans.eb(i, n - 1);
		} else if (i >= n / 2) {
			ans.eb(i, 0);
			ans.eb(0, to);
			ans.eb(i, 0);
		} else {
			ans.eb(i, n-1);
			ans.eb(n-1, 0);
			ans.eb(0, to);
			ans.eb(0, n-1);
			ans.eb(n-1, i);
		}

		swap(pos[i], pos[p[i]]);	
		swap(p[i], p[to]);				
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.fi + 1 << " " << p.se + 1 << "\n";
	}
	return 0;
}