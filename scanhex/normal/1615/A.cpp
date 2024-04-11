#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a(n);
		nagai s = 0;
		for (auto& x : a) 
			cin >> x, s += x;
		if (s % n == 0) 
			cout << 0 << '\n';
		else 
			cout << 1 << '\n';
	}
}