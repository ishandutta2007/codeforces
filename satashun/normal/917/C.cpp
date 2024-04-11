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

const ll INF = TEN(18);

int c[10];
ll dp[256];

ll mem[30][256][256];
V<int> cand;

void precalc(int w, int num) {
	rep(i, 30) {
		rep(j, 256) rep(k, 256) {
			mem[i][j][k] = INF;
		}
	}

	rep(i, 1 << w) {
		if (__builtin_popcount(i) == num) {
			cand.pb(i);
		}
	}

	for (int x : cand) {
		if (x & 1) {
			for (int j = 1; j <= w; ++j) {
				if (!((x >> j) & 1)) {
					int nj = (x >> 1) | (1 << (j-1));
					mem[0][x][nj] = c[j];
				}
			}
		} else {
			chmin(mem[0][x][x >> 1], 0);
		}
	}

	for (int t = 1; t < 30; ++t) {
		for (int x : cand) {
			for (int y : cand) {
				for (int z : cand) {
					chmin(mem[t][x][z], mem[t-1][x][y] + mem[t-1][y][z]);
				}
			}
		}
	}
}

ll nx[256];

void proceed(int l) {
	dump(l);

	int k = 0;
	for (int x : cand) {
		for (int y : cand) {
			if (mem[1][x][y]<INF) {
				dump(mp(mp(x,y),mem[1][x][y]));
			}
		}
	}
	while (l > 0) {
		if (l & 1) {
			rep(i, 256) nx[i] = INF;
			rep(i, 256) if (dp[i] != INF) {
				rep(j, 256) if (mem[k][i][j] < INF) {
					chmin(nx[j], dp[i] + mem[k][i][j]);
				}
			}
			rep(i, 256) dp[i] = nx[i];
		}
		l /= 2;
		k++;
	}
}

map<int, int> ct;

int main() {
	int x, k, n, q; cin >> x >> k >> n >> q;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
	}

	V<pii> vec;
	rep(i, q) {
		int p, w;
		cin >> p >> w;
		vec.eb(p-1, w);
		ct[p-1] = w;
	}
	sort(ALL(vec));

	precalc(k, x);

	rep(i, 1 << k) {
		dp[i] = INF;
	}

	dp[(1 << x) - 1] = 0;

	int la = 0;

	rep(i, q) {
		int p, w;
		tie(p, w) = vec[i];
		dump(mp(p, w));
		int u = p - k;

		if (u > la) {
			dump(mp(la, u));
			proceed(u - la);
			for (int b : cand) {
				if (dp[b] != INF) {
					dump(mp(b, dp[b]));
				}
			}
			la = u;
		}

		for (; la < min(p, n-x); la++) {
			rep(j, 256) {
				nx[j] = INF;
			}

			for (int b : cand) {
				if (dp[b] == INF) continue;
				if (b & 1) {
					for (int d = 1; d <= k && la + d < n; ++d) {
						if (!((b >> d) & 1)) {
							int nj = (b >> 1) | (1 << (d-1));
							chmin(nx[nj], dp[b] + c[d] + (ct.count(la + d) ? ct[la + d] : 0));
						}
					}
				} else {
					chmin(nx[b >> 1], dp[b]);
				}
			}
			rep(j, 256) {
				dp[j] = nx[j];
			}
			dump(la);
			for (int b : cand) {
				if (dp[b] != INF) {
					dump(mp(b, dp[b]));
				}
			}
		}
	}

	int p = n - k;
	if (p > la) {
		dump(mp(la, p));
		proceed(p - la);
		la = p;
	}

	for (int b : cand) {
		if (dp[b] != INF) {
			dump(mp(b, dp[b]));
		}
	}

	for (; la < n - x; la++) {
		rep(j, 256) {
			nx[j] = INF;
		}

		for (int b : cand) {
			if (dp[b] == INF) continue;
			if (b & 1) {
				for (int d = 1; d <= k && la + d < n; ++d) {
					if (!((b >> d) & 1)) {
						int nj = (b >> 1) | (1 << (d-1));
						chmin(nx[nj], dp[b] + c[d] + (ct.count(la + d) ? ct[la + d] : 0));
					}
				}
			} else {
				chmin(nx[b >> 1], dp[b]);
			}
		}
		rep(j, 256) {
			dp[j] = nx[j];
		}
	}

	cout << dp[(1 << x) - 1] << endl;

	return 0;
}