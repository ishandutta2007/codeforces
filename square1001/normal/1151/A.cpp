#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int operations(string s) {
	string t = "ACTG";
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		int d = s[i] - t[i];
		if (d < 0) d *= -1;
		ans += min(d, 26 - d);
	}
	return ans;
}
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 1 << 30;
	for (int i = 3; i < n; ++i) {
		string t = s.substr(i - 3, 4);
		ans = min(ans, operations(t));
	}
	cout << ans << endl;
	return 0;
}