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
		for(auto&x : a)
			cin >> x;
		vector<int> rofl;
		for(int i = 0; i < 1 << n; ++i) {
			int s = 0;
			for(int j = 0; j < n; ++j) 
				if (i >> j & 1)
					s += a[j];
			rofl.push_back(s);
		}
		sort(rofl.begin(), rofl.end());
		rofl.erase(unique(rofl.begin(),rofl.end()), rofl.end());
		if (rofl.size() != (1 << n))  {
			 cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
  return 0;
}