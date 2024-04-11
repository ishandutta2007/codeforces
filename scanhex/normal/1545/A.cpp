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
		vector<int> a(n);
		for(auto&x: a)
			cin >> x;
		map<int, array<int,2>> cnt1;
		for(int i=0;i<n;++i) 
			++cnt1[a[i]][i % 2];
		map<int, array<int,2>> cnt2;
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i) 
			++cnt2[a[i]][i % 2];
		if (cnt1 == cnt2) 
			cout << "YES\n";
		else
			cout << "NO\n";
	}
  return 0;
}