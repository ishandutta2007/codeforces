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

int a[110][110];

int main() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}

	int mini = m;
	V<int> cand;
	rep(i, m) cand.pb(i);

	rep(i, n-1) {
		V<pii> dif;
		rep(j, m) {
			dif.eb(a[j][i] - a[j][n-1], j);
		}
		sort(ALL(dif));
		reverse(ALL(dif));

		int sum = 0;
		int j;
		for (j = 0; j < m && sum + dif[j].fi >= 0; ++j) {
			sum += dif[j].fi;
		}
		V<int> ids;
		for (int k = j; k < m; ++k) {
			ids.pb(dif[k].se);
		}

		if (ids.size() < mini) {
			mini = ids.size();
			cand = ids;
		}
	}

	cout << mini << endl;
	rep(i, mini) {
		cout << cand[i] + 1 << (i == mini - 1 ? '\n' : ' ');
	}

	return 0;
}