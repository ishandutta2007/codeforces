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
#define dump(x) cerr << #x << " = " << (x) << endl
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

string s[100010][2];
bool dp[100010][2];

int main() {
	int n; cin >> n;
	rep(i, n) cin >> s[i][0] >> s[i][1];

	V<int> p(n);
	rep(i, n) {
		cin >> p[i];
		--p[i];
	}

	dp[0][0] = dp[0][1] = 1;

	for (int i = 1; i < n; ++i) {
		rep(j, 2) rep(k, 2) {
			if (s[p[i-1]][j] < s[p[i]][k] && dp[i-1][j]) {
				dp[i][k] = 1;
			}
		}
	}

	puts(dp[n-1][0] || dp[n-1][1] ? "YES" : "NO");
	return 0;
}