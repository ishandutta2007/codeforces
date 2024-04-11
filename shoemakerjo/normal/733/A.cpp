#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	s = s+'A';
	// cout << s << " " << s.length() << endl;
	int dp[s.length()+1];
	for (int i = 1; i <= s.length(); i++) {
		dp[i] = 10000;
	}
	dp[0] = 0;
	for (int i = 1; i <= s.length(); i++) {

		if (s[i-1]=='A' || s[i-1] == 'E' || s[i-1] == 'I' || s[i-1] == 'O' || s[i-1] == 'U' || s[i-1] == 'Y') {
			// cout << s[i] << endl;
			for (int j = 0; j < i; j++) {
				dp[i] = min(dp[i], max(dp[j], i-j));
			}
		}
	}
	cout << dp[s.length()] << endl;
	// cin >> s;
}