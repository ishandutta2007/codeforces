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
		string a, b;
		cin >> a >> b;
		string ans = "YES\n";
		if (n == 1 && a != b)
			ans = "NO\n";
		int bal = (a[0] == '1' ? 1 : -1);
		int last = 0;
		for (int i = 1; i < n; ++i) {
			if (bal != 0 && (a[i] == b[i]) != (a[i - 1] == b[i - 1]))
				ans = "NO\n";
			bal += (a[i] == '1' ? 1 : -1);
			if (bal == 0)
				last = i;
		}
		for (int i = n - 1; i > last; --i)
			if (a[i] != b[i])
				ans = "NO\n";
		cout << ans;
	}
	return 0;
}