#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
	cin >> n;
	vector<int> ret;
	for (int i = n - 500; i <= n; i++) {
		if (i >= 0) {
			string s = to_string(i);
			int res = i;
			for (int j = 0; j < s.size(); j++) res += s[j] - 48;
			if (res == n) ret.push_back(i);
		}
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) cout << ret[i] << endl;
	return 0;
}