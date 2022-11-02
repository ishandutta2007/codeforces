#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int main() {
	cin >> s; s = "a" + s;
	int ret = 0;
	for (int i = 1; i < s.size(); i++) {
		int d = abs(s[i] - s[i - 1]);
		ret += min(d, 26 - d);
	}
	cout << ret << endl;
	return 0;
}