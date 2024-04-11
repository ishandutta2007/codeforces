#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	long long ans = 0;
	int pre = -1;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; i - 2 * j > pre; ++j) {
			if (s[i] == s[i - j] && s[i] == s[i - 2 * j]) {
				pre = i - 2 * j;
				break;
			}
		}
		if (pre != -1) ans += pre + 1;
	}
	cout << ans << endl;
	return 0;
}