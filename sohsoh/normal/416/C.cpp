/*
    Soheil Mohammadkhani
    OK, im back :)
*/
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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll dp[MAXN][MAXN];
pair<ll, pll> A[MAXN];
pll B[MAXN];

int main() {
	fast_io;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].X >> A[i].Y.X, A[i].Y.Y = i;
	ll k;
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> B[i].X, B[i].Y = i;
	sort(A + 1, A + n + 1);
	sort(B + 1, B + k + 1);

	for (int i = 0; i < MAXN; i++) dp[0][i] = {0, -1};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = {0, 1};
			if (A[i].X <= B[j].X) dp[i][j].X = dp[i - 1][j - 1].X + A[i].Y.X, dp[i][j].Y = 0;
			if (dp[i - 1][j - 1].X > dp[i][j].X) dp[i][j].X = dp[i - 1][j - 1].X, dp[i][j].Y = 1; 
			if (dp[i - 1][j].X > dp[i][j].X) dp[i][j].X = dp[i - 1][j].X, dp[i][j].Y = 2; 
			if (dp[i][j - 1].X > dp[i][j].X) dp[i][j].X = dp[i][j - 1].X, dp[i][j].Y = 3; 
		}
	}
	
	vector<pll> v;
	ll p1 = n, p2 = k;
	while (p1 > 0 && p2 > 0) {
		if (dp[p1][p2].Y == 0) {
			v.push_back({A[p1].Y.Y, B[p2].Y});
			p1--;
			p2--;
		} else if (dp[p1][p2].Y == 1) p1--, p2--;
		else if (dp[p1][p2].Y == 2) p1--;
		else p2--;
	}

	reverse(all(v));
	cout << v.size() << sep << dp[n][k].X << endl;
	for (pll e : v) cout << e.X << sep << e.Y << endl;
	return 0;
}