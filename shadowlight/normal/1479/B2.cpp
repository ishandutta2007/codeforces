#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a;
	vector <vector<int>> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (!a.size() || a.back() != x) {
			a.pb(x);
			pos[x].pb(a.size() - 1);
		}
	}
	n = a.size();
	if (n == 1) {
		cout << "1\n";
		return 0;
	}

	vector <int> dp(n + 1, INF);
	dp[2] = 2;
	for (int i = 2; i < n; ++i) {
		if (a[i] != a[i - 2]) {
			dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
		}
		int x = a[i - 2];
		int pp = lower_bound(all(pos[x]), i) - pos[x].begin();
		if (pos[x].size() != pp) {
			int y = pos[a[i - 2]][pp];
			//cout << i << " " << y << endl;
			dp[y + 1] = min(dp[y + 1], dp[i] + (y - i));
		}
		//cout << dp[i] << endl;
	}
	cout << dp[n] << "\n";
}