#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int cycshift_distance(string t1, string t2) {
	// t1 --> t2
	int r = t1.size(); t1 += t1;
	for (int i = 0; i < r; i++) {
		if (t1.substr(i, r) == t2) return i;
	}
	return 12345678;
}
int n, m; string s[55];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	m = s[0].size(); s[0] += s[0];
	int ret = 9999999;
	for (int i = 0; i < m; i++) {
		string t = s[0].substr(i, m);
		int sum = i;
		for (int j = 1; j < n; j++) {
			sum += cycshift_distance(s[j], t);
		}
		ret = min(ret, sum);
	}
	if (ret == 9999999) cout << -1 << endl;
	else cout << ret << endl;
	return 0;
}