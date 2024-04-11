#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>

typedef long long ll;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define input(a) for(auto& _ : a) cin >> _
#define print(a) for (auto _ : a) cout << _
#define x first
#define y second
#define umap unordered_map

//#define int long long

using namespace std;

void solve() {
	ll n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i)
			cout << i << "\n";
		return;
	}
	if (n % 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		int c = i / 2 * 2 * k;
		if (i % 2) {
			for (int j = 0; j < k; ++j)
				cout << c + 1 + j * 2 << " ";
			cout << "\n";
		}
		else {
			for (int j = 0; j < k; ++j)
				cout << c + 2 + j * 2 << " ";
			cout << "\n";
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);



	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}