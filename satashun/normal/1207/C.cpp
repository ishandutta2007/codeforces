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

const int maxn = 200010;
const ll INF = TEN(18);

ll dp[maxn][2];

int main() {
	int T; cin >> T;
	while (T--) {
		string s; int n; ll a, b;
		cin >> n >> a >> b >> s;

		for (int i = 0; i <= n; ++i) {
			dp[i][0] = dp[i][1] = INF;
		}
		dp[0][0] = b;

		rep(i, n) {
			rep(j, 2) if (dp[i][j] != INF) {
				rep(k, 2) {
					if (s[i] == '1' && (j != 1 || k != 1)) continue;
					dp[i+1][k] = min(dp[i+1][k], dp[i][j] + (k + 1) * b + ((j != k) + 1) * a);
				}
			}
		}
		cout << dp[n][0] << "\n";
	}
	return 0;
}