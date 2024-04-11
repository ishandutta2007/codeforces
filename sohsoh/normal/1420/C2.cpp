#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
ll INF = 1e12;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dpp[MAXN][2], n, q;
vector<ll> P[MAXN];
ll dp[MAXN][2];
ll tdp[MAXN][2], tdp2[MAXN][2], PDP[MAXN][2][2];

// 0: pos
// 1: neg
//
void recomp(ll i) {
	ll x = P[i].size();
	tdp[0][0] = -1 * INF, tdp[0][1] = 0;	
	tdp2[0][1] = -1 * INF, tdp2[0][0] = 0;
	for (int j = 0; j < x; j++) {
		tdp[j + 1][0] = max(tdp[j][0], tdp[j][1] + P[i][j]);
		tdp[j + 1][1] = max(tdp[j][1], tdp[j][0] - P[i][j]);	
		tdp2[j + 1][0] = max(tdp2[j][0], tdp2[j][1] + P[i][j]);
		tdp2[j + 1][1] = max(tdp2[j][1], tdp2[j][0] - P[i][j]);		
	}

	PDP[i][0][0] = tdp[x][0];
	PDP[i][0][1] = tdp[x][1];	
	PDP[i][1][0] = tdp2[x][0];
	PDP[i][1][1] = tdp2[x][1];
}

void final_ans(ll m) {
	dp[0][0] = PDP[0][0][0];
	dp[0][1] = PDP[0][0][1];

	for (int i = 1; i <= m; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + PDP[i][1][0]);
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + PDP[i][0][0]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + PDP[i][1][1]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + PDP[i][0][1]);
	}

	cout << max(dp[m][0], dp[m][1]) << endl;
}

ll solve() {
	ll m = 0;
	cin >> n >> q;
	ll sq = sqrt(n);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		P[i / sq].push_back(x), m = i / sq;
	}
	for (int i = 0; i <= m; i++) {
		ll x = P[i].size();
		tdp[0][0] = -1 * INF, tdp[0][1] = 0;
		for (int j = 0; j < x; j++) {
			tdp[j + 1][0] = max(tdp[j][0], tdp[j][1] + P[i][j]);
			tdp[j + 1][1] = max(tdp[j][1], tdp[j][0] - P[i][j]);
		}

		PDP[i][0][0] = tdp[x][0];
		PDP[i][0][1] = tdp[x][1];

		x = P[i].size();
		tdp[0][1] = -1 * INF, tdp[0][0] = 0;
		for (int j = 0; j < x; j++) {
			tdp[j + 1][0] = max(tdp[j][0], tdp[j][1] + P[i][j]);
			tdp[j + 1][1] = max(tdp[j][1], tdp[j][0] - P[i][j]);
		}


		PDP[i][1][0] = tdp[x][0];
		PDP[i][1][1] = tdp[x][1];
	}
	
	final_ans(m);
	while (q--) {
		ll l, r;
		cin >> l >> r; l--, r--;
		ll pl = l / sq, il = l % sq;
		ll pr = r / sq, ir = r % sq;
		swap(P[pl][il], P[pr][ir]);
		recomp(pl);
		recomp(pr);
		final_ans(m);
	}

	for (int i = 0; i < sq + 10; i++) P[i].clear();
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}