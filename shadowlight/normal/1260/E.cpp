#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e18 + 7;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = log2(n);
	bool was = false;
	vector <int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == -1) {
			was = true;
		} else if (was) {
			a.push_back(x);
		}
	}
	vector <vector <ll> > dp(a.size() + 1, vector <ll> (cnt + 1, INF));
	dp[0][0] = 0;
	vector <int> die(1, 0);
	int now = n / 2;
	for (int i = 0; i < cnt; i++) {
		die.push_back(die.back() + now - 1);
		//cout << die.back() << "\n";
		now /= 2;
	}
	reverse(a.begin(), a.end());
	for (int i = 0; i <= (int) a.size(); i++) {
		for (int j = 0; j <= cnt; j++) {
			//cout << i << " " << j << " " << dp[i][j] << "\n";
			int now = (i + 1) - j;
			if (now <= die[j] && i < a.size()) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
			int nxt = (i == a.size() ? i : i + 1);
			if (j < cnt) {
				dp[nxt][j + 1] = min(dp[nxt][j + 1], dp[i][j] + (i < (int) a.size() ? a[i] : 0));
			}
		}
	}
	cout << dp[(int) a.size()][cnt] << "\n";
}