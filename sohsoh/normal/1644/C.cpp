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

const ll MAXN = 5e3 + 10;
const ll INF = 1e18;

ll dp[MAXN], suff[MAXN], ps[MAXN], A[MAXN], n, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 0; i < MAXN; i++)
			dp[i] = suff[i] = -INF;
		dp[0] = 0;

		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			ps[i] = ps[i - 1] + A[i];

			for (int j = 1; j <= i; j++)
				dp[j] = max(dp[j], ps[i] - ps[i - j]);
		}

		for (int i = n; i >= 0; i--)
			suff[i] = max(suff[i + 1], dp[i]);

		cout << suff[0] << sep;
		for (int i = 1; i <= n; i++) {
			dp[i] = max(dp[i - 1], suff[i] + i * x);
			cout << dp[i] << sep;
		}

		cout << endl;
	}
	return 0;
}