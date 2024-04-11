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

bool ex(const V<int>& vec, int x) {
	auto p = lower_bound(ALL(vec), x) - vec.begin();
	if (p < vec.size() && vec[p] == x) {
		return true;
	} else {
		return false;
	}
}

const int maxn = 2000010;
int dp[2][maxn];
pii pre[2][maxn];

int main() {
	int n, m1, m2, t;
	scanf("%d %d %d %d", &n, &m1, &m2, &t);
	V<int> v1(m1), v2(m2);
	V<int> xs((m1 + m2) * 2);
	int now = 0;
	rep(i, m1) {
		scanf("%d", &v1[i]);
		xs[now++] = v1[i];
		xs[now++] = v1[i] + 1;
	}
	rep(i, m2) {
		scanf("%d", &v2[i]);
		xs[now++] = v2[i];
		xs[now++] = v2[i] + 1;		
	}
	xs.pb(0);
	xs.pb(n + 1);
	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());
	dump(xs);

	memset(dp, -1, sizeof(dp));
	dp[0][0] = dp[1][0] = 0;
	pre[1][0] = mp(0, 0);

	for (int i = 1; i < xs.size(); ++i) {
		rep(r, 2) {
			if (dp[r][i-1] != -1) {
				int nx = dp[r][i-1] + xs[i] - xs[i-1] - 1;
				if (ex((r == 0 ? v1 : v2), xs[i])) {
					if (nx >= t) {
						//chmax(dp[0][i], nx - t + 1);
						if (dp[r][i] < nx - t + 1) {
							pre[r][i] = mp(r, i-1);
							dp[r][i] = nx - t + 1;
						}
					}
				} else {
					//chmax(dp[0][i], nx + 1);
					if (dp[r][i] < nx + 1) {
						dp[r][i] = nx + 1;
						pre[r][i] = mp(r, i-1);
					}
				}
			}
		}
		if (!ex(v1, xs[i])) {
			//chmax(dp[0][i], dp[1][i]);
			int nx = min(t, dp[1][i]);
			if (dp[0][i] < nx) {
				dp[0][i] = nx;
				pre[0][i] = mp(1, i);
			}			
		}
		if (!ex(v2, xs[i])) {
			//chmax(dp[1][i], dp[0][i]);
			int nx = min(t, dp[0][i]);
			if (dp[1][i] < nx) {
				dp[1][i] = nx;
				pre[1][i] = mp(0, i);
			}
		}
	}

	if (dp[1][xs.size()-1] == -1 && dp[0][xs.size()-1] == -1) {
		puts("No");
		return 0;
	}
	puts("Yes");
	int r = -1, c = -1;
	V<pii> vec;
	V<int> turns;
	rep(i, 2) {
		if (dp[i][xs.size()-1] != -1) {
			r = i, c = xs.size()-1;
			break;
		}
	}

	V<pii> fires;
	const int INF = TEN(9) * 2;
	int la = INF;

	while (true) {
		vec.eb(r, c);
		if (mp(r, c) == mp(0, 0)) {
			break;
		}

		pii nx = pre[r][c];
		if (c == nx.se) {
			turns.eb(xs[c]);
		} else {
			if (dp[r][c] < dp[nx.fi][nx.se] + xs[c] - xs[nx.se]) {
				fires.eb(r, min(xs[c] - 1, la - t));
				la = min(xs[c] - 1, la - t);
			}
		}
		tie(r, c) = nx;
	}

	reverse(ALL(turns));
	reverse(ALL(fires));

	int nt = turns.size();
	printf("%d\n", nt);
	rep(i, nt) {
		printf("%d ", turns[i]);
	}
	puts("");

	int nf = fires.size();
	printf("%d\n", nf);
	rep(i, nf) {
		printf("%d %d\n", fires[i].se, fires[i].fi + 1);
	}
	return 0;
}