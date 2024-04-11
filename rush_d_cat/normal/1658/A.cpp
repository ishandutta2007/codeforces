#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t --) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> v;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') v.push_back(i);
		}
		int ans = 0;
		for (int i = 1; i < v.size(); i ++) ans += max(3 - (v[i] - v[i-1]), 0);
		cout << ans << "\n";
	}
}