#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int up = 0, down = 0, left = 0, right = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'U') up++;
		if (s[i] == 'D') down++;
		if (s[i] == 'L') left++;
		if (s[i] == 'R') right++;
	}
	// cout << up << " " << down << " " << left << " " << right << endl;
	if (s.length()%2 == 1) {
		cout << -1 << endl;
	}
	else {
		int ans = s.length();
		int n = s.length();
		for (int i = 0; i <= s.length()/2; i++) {
			int ot = (n-2*i)/2;
			int cur = abs(left-i)+abs(right-i)+
				abs(up-ot)+abs(down-ot);
			cur = cur/2;
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
	cin >> s;
}