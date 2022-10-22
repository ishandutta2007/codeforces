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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, m - 1);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = -1;
	for (int cnt = 0; cnt <= k; cnt++) {
		vector <int> b;
		int now = cnt;
		while (b.size() != n - k) {
			b.push_back(a[now++]);
		}
		/*for (int x : b) {
			cout << x << " ";
		}
		cout << "\n";*/
		int dist = n - m;
		now = INF;
		for (int i = 0; i < (int) b.size(); i++) {
			if (i + dist >= b.size()) continue;
			now = min(now, max(b[i], b[i + dist]));
		}
		res = max(res, now);
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}