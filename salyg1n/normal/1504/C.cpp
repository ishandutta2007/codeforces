#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt1 = 0;
		for (auto i : s)
			if (i == '1')
				cnt1++;
		if (s[0] == '0' || s[n - 1] == '0' || cnt1 % 2 != 0) {
			cout << "NO\n";
			continue;
		}
		int c1 = 0;
		string s1, s2;
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				if (c1 * 2 < cnt1) {
					s1 += '(';
					s2 += '(';
				}
				else {
					s1 += ')';
					s2 += ')';
				}
				c1++;
			}
			else {
				if (k % 2 == 0) {
					s1 += '(';
					s2 += ')';
				}
				else {
					s1 += ')';
					s2 += '(';
				}
				k++;
			}
		}
		cout << "YES\n";
		cout << s1 << "\n" << s2 << "\n";
	}
	return 0;
}