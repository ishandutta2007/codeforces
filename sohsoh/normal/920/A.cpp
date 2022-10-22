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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k;
bool B[MAXN];

inline int solve() {
	memset(B, false, sizeof B);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		B[x] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tans = n;
		for (int j = 1; j <= n; j++) 
			if (B[j])
				tans = min(tans, abs(i - j) + 1);
		ans = max(ans, tans);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}