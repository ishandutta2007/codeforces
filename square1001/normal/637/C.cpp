#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s[1009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ret = 999999999;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int p = 0;
			for (int k = 0; k < 6; k++) p += (s[i][k] != s[j][k]);
			ret = min(ret, (p - 1) / 2);
		}
	}
	cout << min(ret, 6) << endl;
	return 0;
}