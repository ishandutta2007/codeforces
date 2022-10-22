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

#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << H;
	debug_out(T...);
}
#define debug(...) cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int dp[510][510];
const int INF = TEN(9);

int main() {
	int n, m, k; cin >> n >> m >> k;

	rep(i, 510) rep(j, 510) dp[i][j] = INF;
	dp[0][0] = 0;

	rep(i, n) {
		string s; cin >> s;
		V<int> mini(k + 1, INF);

		int all = 0;
		for (auto c : s) {
			if (c == '1') {
				all++;
			}
		}

		if (all <= k) {
			chmin(mini[all], 0);
		}

		rep(j, s.size()) {
			int u = 0;
			for (int t = j; t < s.size(); ++t) {
				if (s[t] == '1') u++;
				if (all - u <= k) {
					chmin(mini[all - u], t - j + 1);
				}
			}
		}

		rep(j, 510) if (dp[i][j] != INF) {
			for (int t = 0; t <= k; ++t) {
				if (j + t <= k) {
					chmin(dp[i+1][j+t], dp[i][j] + mini[t]);
				}
			}
		}
	}
	cout << *min_element(dp[n], dp[n] + k + 1) << endl;

	return 0;
}