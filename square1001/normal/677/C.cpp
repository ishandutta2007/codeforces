#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int ret = 1;
	for (int i = 0; i < s.size(); i++) {
		int x = (s[i] <= 57 ? s[i] - 48 : (s[i] <= 90 ? s[i] - 55 : s[i] - 61));
		if (s[i] == '-') x = 62;
		if (s[i] == '_') x = 63;
		for (int j = 0; j < 6; j++) {
			if (!(x & (1 << j))) ret = 1LL * ret * 3 % 1000000007;
		}
	}
	cout << ret << endl;
	return 0;
}