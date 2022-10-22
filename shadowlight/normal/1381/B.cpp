#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2007;

pair <int, int> pred[N][N];
bool dp[N][N];

void solve() {
	int n;
	cin >> n;
	vector <int> p(2 * n);
	set <pair <int, int> > q;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> p[i];
		q.insert({p[i], i});
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			//pred[i][j] = {-1, -1};
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	int cnt = 0;
	while (cnt < 2 * n) {
		int now = 0;
		int pos = q.rbegin()->y;
		for (int d = (2 * n - 1) - cnt; d >= pos; --d) {
			++now;
			q.erase({p[d], d});
		}
		//cout << cnt << " " << now << " " << 2 * n << endl;
		for (int i = 0; i <= cnt; ++i) {
			if (i > n || cnt - i > n) continue;
			if (!dp[i][cnt - i]) continue;
			if (i + now <= n) {
				dp[i + now][cnt - i] = 1;
				//pred[i + now][cnt - i] = {i, cnt - i};
			}
			if (cnt - i + now <= n) {
				dp[i][cnt - i + now] = 1;
				//pred[i][cnt - i + now] = {i, cnt - i};
			}
		}
		cnt += now;
	}
	cout << (dp[n][n] ? "YES" : "NO") << "\n";
}


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}