#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		long long ans;
		string s;
		cin >> x;
		cin >> s;
		ans = s.length();
		for (int j = 0; j < x; ++j) {
			if (s[j] == '1') continue;
			else if (s.length() >= x) ans = ((s[j] - '0') * ans - (s[j] - '0' - 1) * (j + 1)) % 1000000007;
			else {
				for (int k = j + 1; k < ans; ++k) s.push_back(s[k]);
				if (s[j] == '3') {
					for (int k = j + 1; k < ans; ++k) s.push_back(s[k]);
				}
				ans = s.length();
			}
		}
		cout << (ans + 1000000007) % 1000000007 << '\n';
	}
	return 0;
}