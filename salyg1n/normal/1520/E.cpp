#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	for (ll T = 0; T < t; ++T) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*')
				a.push_back(i);
		}
		if (a.size() <= 1) {
			cout << 0 << "\n";
			continue;
		}
		bool check = true;
		int num = -1;
		while (check) {
			num++;
			int l = -1, r = a.size();
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (a[m] > num + m)
					r = m;
				else
					l = m;
			}
			if (r <= (a.size() - 1) / 2)
				check = true;
			else
				check = false;
		}
		ll ans = 0;
		for (int i = 0; i < a.size(); ++i) {
			ans += abs(a[i] - (num + i));
		}
		cout << ans << "\n";
	}
	return 0;
}