#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e3 + 10;

int n, k, ind;
ll dp[MAXN][MAXN], S[MAXN], ans;
vector<int> vec[MAXN];

inline void add(int x) {
	++ind;
	dp[ind][0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[ind][i] = max(dp[ind][i - 1], dp[ind - 1][i]);
		if (i >= (int) vec[x].size()) dp[ind][i] = max(dp[ind][i], dp[ind - 1][i - vec[x].size()] + S[x]);
	}
}

inline void solve(int l, int r) {
	if (l == r) {
		ll s = 0;
		for (int i = 0; i <= k; i++) {
			ans = max(ans, dp[ind][k - i] + s);
			if (i < (int) vec[l].size()) s += vec[l][i];
		}
		
		return;
	} 

	int mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) add(i);
	solve(mid + 1, r);
	ind -= mid - l + 1;

	for (int i = mid + 1; i <= r; i++) add(i);
	solve(l, mid);
	ind -= r - mid;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int l;
		cin >> l;
		for (int j = 0; j < l; j++) {
			int x;
			cin >> x;
			S[i] += x;
			vec[i].push_back(x);
		}
	}

	solve(1, n);
	cout << ans << endl;
	return 0;
}