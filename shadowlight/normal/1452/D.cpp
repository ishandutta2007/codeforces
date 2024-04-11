#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <int> dp(n + 1, 0);
	vector <int> p(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	p[0] = 1;
	p[1] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i] = p[i - 1];
		p[i] = (dp[i] + p[i - 2]) % MOD;
	} 

	int res = dp[n];

	for (int i = 0; i < n; ++i) {
		res = res * (ll) (MOD + 1) / 2 % MOD;
	}

	cout << res << "\n";

}