#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	int lp = 0; vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if (i == n || s[i - 1] != s[i]) {
			if (s[i - 1] == 'B') ret.push_back(i - lp);
			lp = i;
		}
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) {
		if (i) cout << ' ';
		cout << ret[i];
	}
	cout << endl;
	return 0;
}