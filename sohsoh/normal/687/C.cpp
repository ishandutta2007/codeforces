// Sohsoh84 :)))
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

const ll MAXN = 500 + 10;

int n, tk, C[MAXN];
bool dp[2][MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> tk;
	
	dp[0][0][0] = true;
	for (int i = 1; i <= n; i++) {
		int x, ind = i & 1;
		cin >> x;

		for (int j = 0; j <= tk; j++) {
			for (int k = 0; k <= j; k++) {
				dp[ind][j][k] = dp[1 - ind][j][k];
				if (j >= x) dp[ind][j][k] |= dp[1 - ind][j - x][k];
				if (k >= x) dp[ind][j][k] |= dp[1 - ind][j - x][k - x];
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i <= tk; i++)
		if (dp[n & 1][tk][i])
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int e : ans)
		cout << e << sep;
	cout << endl;
	return 0;
}