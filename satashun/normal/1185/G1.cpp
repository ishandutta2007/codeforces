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

const ll MOD = 1000000007;

int dp[26][26][26][2501];

inline void add(int &x, int y) { x += y; if (x >= MOD) x -= MOD; }

ll way[3][51][51][51];

int main() {
	way[0][1][0][0] = way[1][0][1][0] = way[2][0][0][1] = 1;

	for (int i = 0; i <= 50; ++i) {
		for (int j = 0; j <= 50; ++j) {
			for (int k = 0; k <= 50; ++k) {
				rep(c, 3) if (way[c][i][j][k]) {
					rep(u, 3) if (u != c) {
						if (u == 0 && i+1 <= 50) (way[u][i+1][j][k] += way[c][i][j][k] * (i+1)) %= MOD;
						if (u == 1 && j+1 <= 50) (way[u][i][j+1][k] += way[c][i][j][k] * (j+1)) %= MOD;
						if (u == 2 && k+1 <= 50) (way[u][i][j][k+1] += way[c][i][j][k] * (k+1)) %= MOD;
					}
				}
			}
		}
	}

	int n, T; cin >> n >> T;

	dp[0][0][0][0] = 1;

	int m = 0;
	rep(i, n) {
		int t, g; cin >> t >> g;

		for (int a = min(i, 25); a >= 0; --a) {
			for (int b = min(i-a, 25); b >= 0; --b) {
				for (int c = min(i-a-b, 25); c >= 0; --c) {	
					for (int s = min(T-t, m); s >= 0; --s) if (dp[a][b][c][s] != 0) {
						if (g == 1) add(dp[a+1][b][c][s + t], dp[a][b][c][s]);
						else if (g == 2) add(dp[a][b+1][c][s + t], dp[a][b][c][s]);
						else add(dp[a][b][c+1][s + t], dp[a][b][c][s]);
					}
				}
			}
		}
		m += t;
	}

	int ans = 0;
	for (int a = 25; a >= 0; --a) {
		for (int b = 25; b >= 0; --b) {
			for (int c = 25; c >= 0; --c) {	
				if (dp[a][b][c][T] != 0) {
					ll u = dp[a][b][c][T] * (way[0][a][b][c] + way[1][a][b][c] + way[2][a][b][c]) % MOD;
					add(ans, (int)u);
				}
			}
		}
	}	

	cout << ans << endl;

	return 0;
}