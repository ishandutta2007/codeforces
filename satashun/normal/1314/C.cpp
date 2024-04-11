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

ll dp[1010][1010];

int main() {
	int n, m; ll k;
	cin >> n >> m >> k;
	string s; cin >> s;

	auto tor = [&](string &t, int l) {
		int now = 0;
		int state = -1;
		for (int r = l; r < n; ++r) {
			if (state != -1) {
				break;
			}			
			if (now < t.size()) {
				if (t[now] > s[r]) {
					state = 0;
					return -1;
				}
				if (t[now] < s[r]) {
					state = 1;
					return r;
				}
				now++;
			}
			if (now == t.size()) {	
				return r;
			}
		}
		return -1;
	};

	auto ok = [&](string t) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		V<int> rs(n);
		rep(i, n) rs[i] = tor(t, i);
		if (rs[0] == -1) return false;
		dp[1][rs[0]+1] = 1;
		for (int i = 1; i <= m; ++i) {
			rep(j, n) {
				if (i < m) {
					if (dp[i][j] != 0 && rs[j] != -1) {
						dp[i+1][rs[j]+1] += dp[i][j];
						chmin(dp[i+1][rs[j]+1], k); 
					}
				}
				dp[i][j+1] += dp[i][j];
				chmin(dp[i][j+1], k); 
			}
		}
		dump(mp(t, dp[m][n]));
		return dp[m][n] == k;
	};

	V<string> vec;
	rep(i, n) {
		string t;
		for (int j = i; j < n; ++j) {
			t.pb(s[j]);
			vec.pb(t);
		}
	}

	sort(ALL(vec));
	int lo = 0, hi = (int)vec.size()-1;
	if (ok(vec[hi])) {
		lo = hi;
	}

	dump(vec);

	while (hi - lo > 1) {
		int m = (lo + hi) / 2;
		if (ok(vec[m])) {
			lo = m;
		} else {
			hi = m;
		}
	}
	cout << vec[lo] << endl;

	return 0;
}