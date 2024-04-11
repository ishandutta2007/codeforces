#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int n;
const int maxn = 100010;

ll vals[maxn];
int deg[maxn];

void solve() {
	cin >> n;
	ll res = 0LL;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
		deg[i] = 0;
		res += vals[i];
	}
	// ll res = 0
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	vector<ll> addins;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= deg[i]; j++) {
			addins.push_back(vals[i]);
		}
	}
	sort(addins.begin(), addins.end());
	reverse(addins.begin(), addins.end());

	for (int i = 1; i <= n-1; i++) {
		if (i > 1) res += addins[i-2];
		cout << res << " ";
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) solve();

	cout.flush();

}