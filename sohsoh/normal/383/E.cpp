// \_()_/
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
const ll MSK = (1 << 24);

int n;
int dp[MSK];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int c1 = int(s[0] - 'a'), c2 = int(s[1] - 'a'),
			c3 = int(s[2] - 'a');
		dp[(1 << c1) | (1 << c2) | (1 << c3)]++;	
	}

	for (int i = 0; i < 24; i++)
		for (int msk = 0; msk < MSK; msk++)
			if (msk & (1 << i)) 
				dp[msk] += dp[msk ^ (1 << i)];
	
	ll ans = 0;
	for (int msk = 0; msk < MSK; msk++)
		ans ^= 1ll * (n - dp[msk]) * (n - dp[msk]);
	cout << ans << endl;
	return 0;
}