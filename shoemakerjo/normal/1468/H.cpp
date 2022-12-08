#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int n, k, m;
const int maxn = 200010;

bool isin[maxn];

bool solve() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) isin[i] = false;
	int cur;
	int nrem = n - m;
	for (int i = 0; i < m; i++) {
		cin >> cur;
		isin[cur] = true;
	}
	if (nrem % (k-1) != 0) return false;
	int nseen = 0;
	for (int i = 1; i <= n; i++) {
		if (!isin[i])  {
			nseen++;
			continue;
		}
		if (nseen >= (k-1)/2 && nrem - nseen >= (k-1)/2) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		bool res = solve();
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}