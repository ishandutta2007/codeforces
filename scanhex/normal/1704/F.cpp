#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	vector<int> grand = {0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,
 0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,
 5,5,2,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,
 1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,
 3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,
 1,3,0,2,1,1,0,4};
	while (t--) {
		int n; 
		cin >> n;
		string s;
		cin >> s;
		vector<int> lens; 
		int bal = 0;
		int cur = 0;
		for(char ch : s) 
			if (ch == 'R')
				++bal;
			else
				--bal;
		if (bal > 0) {
			 cout << "Alice\n";
			 continue;
		}
		else if (bal < 0) {
			 cout << "Bob\n";
			 continue;
		}
		for(int i = 1; i < n; ++i) {
			if (s[i] == s[i - 1]) {
				if (cur > 0) 
					lens.push_back(cur);
				cur = 0;
			}
			else {
				++cur;
			}
		}
		if (cur > 0) 
			lens.push_back(cur);
		int res = 0;
		for(int x : lens) {
			if (x < grand.size()) 
				res ^= grand[x];
			else {
				 x %= 34;
				 while (x + 34 < grand.size()) x += 34;
				 res ^= grand[x];
			}
		}
		if (res != 0) {
			 cout << "Alice\n";
			 continue;
		}
		else {
			cout << "Bob\n";
		}
	}
}