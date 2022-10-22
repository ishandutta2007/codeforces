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
		 vector<nagai> sums;
		 map<nagai, int> cnt;
		 for(int i = 0; i < n; ++i) {
			 nagai s = 0;
			 for(int j = 0; j < m; ++j) {
				 nagai x;
				 cin >> x;
				 s += x * j;
			 }
			 sums.push_back(s);
			 cnt[s]++;
		 }
		 for(int k = 0; k < n; ++k) {
			 if (cnt[sums[k]] == 1) {
				 nagai other = 0;
				 for(auto& p : cnt) 
					 if (p.first != sums[k]) 
						 other = p.first;
				 cout << k + 1 << ' ' << sums[k] - other << '\n';
			 }
		 }
	}
}