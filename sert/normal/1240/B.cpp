#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = (int)1e9 + 41;

ll getSum(const vector<ll> &p, int l, int r) {
	return p[r] - p[l];
}

void solve() {
	int n;
	cin >> n;
	vector<int> dp(n + 3, INF);
	dp[0] = -INF;
	vector<int> a(n);
	vector<int> l(n, -1), r(n, -1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		if (l[x] == -1) l[x] = i;
		r[x] = i;
	}
	int num = 0;
	for (int i = 0; i < n; i++) if (l[i] != -1) num++;

	int mx = 0;
	int lst = -1;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (l[i] == -1) continue;
		if (l[i] < lst) {
			mx = max(mx, cur);
			lst = r[i];
			cur = 1;
		} else {
			lst = r[i];
			cur++;
		}
	}

	mx = max(mx, cur);

	cout << num - mx << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}