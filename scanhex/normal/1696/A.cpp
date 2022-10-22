#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		nagai z;
		cin >> n >> z;
		vector<nagai>a(n);
		nagai res = 0;
		for(auto& x : a){ 
			cin >> x;
			res = max(res, x);
			res = max(res, x | z);
		}
		cout << res << '\n';
	}
}