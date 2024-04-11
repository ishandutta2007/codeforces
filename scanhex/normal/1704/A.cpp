#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		if (a.size() < b.size()) {
			cout << "NO\n";
			continue;
		}
		int mn = a[0] - '0';
		int mx = mn;
		while (a.size() >= b.size()) {
			mn = min(mn, a.front() - '0');
			mx = max(mx, a.front() - '0');
			a.erase(a.begin());
		}
		int rfl = b.front() - '0';
		b.erase(b.begin());
		if (mn <= rfl && rfl <= mx && a == b) 
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}