#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <ll> suf(n - 1, 0);
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = (i < n - 2 ? suf[i + 1] : 0) + a[i + 1];
		//cout << i << " " << suf[i] << "\n";
	}
	ll res = suf[0] + a[0];
	sort(suf.rbegin(), suf.rend());
	//cout << res << "\n";
	for (int i = 0; i < k - 1; i++) {
		res += suf[i];
	}
	cout << res << "\n";
}