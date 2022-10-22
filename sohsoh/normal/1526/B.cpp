#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	dp[0] = true;
	for (int i = 1; i < MAXN; i++) {
		if (i >= 11) dp[i] |= dp[i - 11];
		if (i >= 111) dp[i] |= dp[i - 111];
		if (i >= 1111) dp[i] |= dp[i - 1111];
	}

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x < MAXN) cout << (dp[x] ? "YES" : "NO") << endl;
		else cout << "YES" << endl;
	}
	return 0;
}