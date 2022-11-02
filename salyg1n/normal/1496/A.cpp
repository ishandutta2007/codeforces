#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <time.h>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s; 
		if (k > (n - 1) / 2) {
			cout << "NO\n";
			continue;
		}
		string ans = "YES";
		for (int i = 0; i < k; ++i) {
			if (s[i] != s[n - i - 1]) {
				ans = "NO";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}