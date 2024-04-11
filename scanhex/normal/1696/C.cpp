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
		vector<int>a(n);
		nagai s1 = 0;
		for(auto&x : a) cin >> x, s1 += x;
		int k;
		cin >> k;
		vector<int>b(k);
		nagai s2 = 0;
		for(auto&x : b) cin >> x, s2 += x;
		vector<pair<nagai, nagai>> aa, bb;
		for(auto& x : a) {
			nagai c = 1;
			while (x % m == 0) {
				x /= m;
				c *= m;
			}
			aa.push_back({x, c});
		}
		for(auto& x : b) {
			nagai c = 1;
			while (x % m == 0) {
				x /= m;
				c *= m;
			}
			bb.push_back({x, c});
		}
		int ptr2 = 0;
		bool ok = true;
		for(auto& [x, c]: aa) {
			while (c > 0) {
				while (ptr2 < bb.size() && bb[ptr2].second == 0) 
					++ptr2;
				if (ptr2 == bb.size())  {
					ok = false;
					break;
				}
				if (bb[ptr2].first != x) {
					ok = false;
				}
				nagai cc = min(c, bb[ptr2].second);
				bb[ptr2].second -= cc;
				c -= cc;
			}
		}
		while (ptr2 < bb.size() && bb[ptr2].second == 0) 
			++ptr2;
		if (ptr2 < bb.size()) ok = false;
		if (ok) 
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}