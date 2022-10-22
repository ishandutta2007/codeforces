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

int dp[410][410];

int main() {
	int TC; cin >> TC;
	while (TC--) {
		string s, t;
		cin >> s >> t;
		int n = s.size(), m = t.size();
		bool ok = 0;

		rep(i, m) { //[0,i],[i+1,m)
			int l = i + 1, r = m - l;
			rep(j, n+1) {
				rep(k, l+1) {
					dp[j][k] = -1;
				}
			}
			dp[0][0] = 0;

			rep(j, n) {
				rep(k, l+1) {
					chmax(dp[j+1][k], dp[j][k]);
					if (dp[j][k] != -1) {
						if (k < l && s[j] == t[k]) {
							chmax(dp[j+1][k+1], dp[j][k]);
						}
						int a = dp[j][k];
						if (a < r && s[j] == t[l + a]) {
							chmax(dp[j+1][k], dp[j][k] + 1);
						}
					}
				}
			}
			if (dp[n][l] == r) {
				ok = 1;
			}
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}