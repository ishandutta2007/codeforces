#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<int> qBefore(n, 0);
	for (int i = 1; i < n; ++i) {
		qBefore[i] = qBefore[i-1] + (s[i-1] == 'Q');
	}
	vector<int> qAfter(n, 0);
	for (int i = n - 2; i >= 0; --i) {
		qAfter[i] = qAfter[i+1] + (s[i+1] == 'Q');
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			ans += qBefore[i] * qAfter[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}