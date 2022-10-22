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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bitset<MAXN> knapsack;
int dp[MAXN];
int n, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	knapsack[0] = true;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		knapsack |= knapsack << x;
	}

	fill(dp, dp + MAXN, INF);
	dp[0] = 0;
	multiset<int> st = {0};
	for (int i = 1; i < MAXN; i++) {
		if (i > d && knapsack[i - d - 1]) st.erase(st.find(dp[i - d - 1]));
		if (!knapsack[i]) continue;
		if (!st.empty()) dp[i] = min(dp[i], (*st.begin()) + 1);
		st.insert(dp[i]);
	}

	int ans = 0, ans_t = 0;
	for (int i = 1; i < MAXN; i++)
		if (dp[i] < INF) ans = i, ans_t = dp[i];
	cout << ans << sep << ans_t << endl;
	return 0;
}