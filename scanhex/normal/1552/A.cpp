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
		string s;
		cin >> s;
		auto s1 = s;
		sort(s1.begin(),s1.end());
		int k = 0;
		for(int i = 0; i < s.size(); ++i) 
			if (s[i] != s1[i]) ++k;
		cout << k << '\n';
	}
  return 0;
}