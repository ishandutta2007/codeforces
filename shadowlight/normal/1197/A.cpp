#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int k = min({n - 2, a.back() - 1, a[a.size() - 2] - 1});
	cout << k << "\n";
}

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}