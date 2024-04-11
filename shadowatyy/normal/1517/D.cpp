#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 507;

int n, m, k;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

int dp[11][23][23];

int e[N][N][4];

bool ins(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int depe(int x, int y) {

	for (int l = 0; l <= k; ++l) {
		for (int i = 0; i <= 22; ++i) {
			memset(dp[l][i],  0x3f3f3f3f, sizeof(dp[l][i]));
			// int ai = abs(i);
			// for (int j = 0; j <= 22; ++j) {
			// 	dp[l][i][j] = inf;
			// }
		}
	}
	
	dp[0][11 + 0][11 + 0] = 0;

	for (int l = 1; l <= k; ++l) {
		for (int i = -l; i <= l; ++i) {
			int ai = abs(i);
			int lo = -(l - ai);
			// while (y + lo < 1)
			// 	lo += 2;

			int hi = (l - ai);
			// while (y + hi > m)
			// 	hi -= 2;

			for (int j = lo; j <= hi; j += 2) {
				
				if (!ins(x + i, y + j))
					continue;

				for (int d = 0; d < 4; ++d) {
					int ne = dp[l - 1][11 + i - X[d]][11 + j - Y[d]] + e[x + i][y + j][d ^ 1];
					dp[l][11 + i][11 + j] = min(dp[l][11 + i][11 + j], ne);
					
				}
			}
		}
	}

	int ans = inf;

	for (int i = 0; i <= 22; ++i) {
		for (int j = 0; j <= 22; ++j) {
			ans = min(ans, dp[k][i][j]);
		}
	}

	return 2 * ans;
}

void solve () {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			int w;
			cin >> w;
			e[i][j][0] = w;
			e[i][j + 1][1] = w;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int w;
			cin >> w;
			e[i][j][2] = w;
			e[i + 1][j][3] = w;
		}
	}

	if (k % 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << -1 << " ";
			}

			cout << endl;
		}

		return;
	}

	k /= 2;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << depe(i, j) << " ";
		}

		cout << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	solve();
}