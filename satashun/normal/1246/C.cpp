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

const ll MOD = TEN(9) + 7;
const int maxn = 2010;

inline void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

char s[maxn][maxn];
bool f[maxn][maxn];
ll dp[maxn][maxn][2];
int numr[maxn][maxn];
int numd[maxn][maxn];
ll ac[maxn][maxn][2];

inline ll get(int k, int a, int b, int c, int d) {
	ll v = ac[b+1][d+1][k] - ac[b+1][c][k] - ac[a][d+1][k] + ac[a][c][k];
	v %= MOD;
	if (v < 0) v += MOD;
	return v;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%s", s[i]);
	rep(i, n) rep(j, m) f[i][j] = (s[i][j] == 'R');
	rep(i, n) {
		for (int j = m-1; j >= 0; --j) {
			numr[i][j] = numr[i][j+1] + f[i][j];
		}
	}
	rep(j, m) {
		for (int i = n-1; i >= 0; --i) {
			numd[i][j] = numd[i+1][j] + f[i][j];
		}
	}

	if (n == 1 && m == 1) {
		puts("1");
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0][1] = (numd[0][0] + i < n);
		ac[i+1][1][1] = ac[i][1][1] + dp[i][0][1];
	}

	for (int j = 1; j < m; ++j) {
		dp[0][j][0] = (numr[0][0] + j < m);
		ac[1][j+1][0] = ac[1][j][0] + dp[0][j][0];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			ac[i+1][j+1][0] = (ac[i][j+1][0] + ac[i+1][j][0] - ac[i][j][0]) % MOD;
			ac[i+1][j+1][1] = (ac[i][j+1][1] + ac[i+1][j][1] - ac[i][j][1]) % MOD;

			if (j != 0) {
				bool ok = 1;
				int lo = 0, hi = j;
				if (numr[i][lo + 1] + j < m) {
					hi = 0;
				}
				if (numr[i][hi + 1] + j >= m) {
					ok = 0;
				}
				while (hi - lo > 1) {
					int mid = (lo + hi) / 2;
					if (numr[i][mid+1] + j < m) {
						hi = mid;
					} else {
						lo = mid;
					}
				}
				if (ok) {
					dp[i][j][0] = get(1, i, i, hi, j-1);
				}
				/*
				for (int k = j-1; k >= 0; --k) {
					if (numr[i][k+1] + j < m) {
						add(dp[i][j][0], dp[i][k][1]);
					}
				}*/
			}
			if (i != 0) {
				bool ok = 1;
				int lo = 0, hi = i;
				if (numd[lo + 1][j] + i < n) {
					hi = 0;
				}
				if (numd[hi + 1][j] + i >= n) {
					ok = 0;
				}
				while (hi - lo > 1) {
					int mid = (lo + hi) / 2;
					if (numd[mid+1][j] + i < n) {
						hi = mid;
					} else {
						lo = mid;
					}
				}
				if (ok) {
					dp[i][j][1] = get(0, hi, i-1, j, j);
				}				
				/*
				for (int k = i-1; k >= 0; --k) {
					if (numd[k+1][j] + i < n) {
						add(dp[i][j][1], dp[k][j][0]);
					}
				}*/
			}
			add(ac[i+1][j+1][0], dp[i][j][0]);
			add(ac[i+1][j+1][1], dp[i][j][1]);
		}
	}

	ll ans = (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % MOD;

	cout << ans << endl;

	return 0;
}