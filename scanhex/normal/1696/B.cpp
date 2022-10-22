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
		cin >> n;
		vector<int>a(n);
		int c0 = 0;
		for(auto& x : a) {
			cin >> x;
			c0 += x == 0;
		}
		int ptr0 = 0;
		while (ptr0 < n && a[ptr0] == 0) ++ptr0; 
		int ptr1 = 0;
		while (ptr1 < n && a[n - ptr1 - 1] == 0) ++ptr1;
		if (c0 == n) 
			cout << 0 << '\n';
		else if (ptr1 + ptr0 < c0)
			cout << 2 << '\n'; 
		else
			cout << 1 << '\n';
	}
}