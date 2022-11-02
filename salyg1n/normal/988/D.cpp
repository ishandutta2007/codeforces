#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set<ll> s;
	vector<ll> a;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		s.insert(x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	vector<ll> ans = {a[0]};
	bool flag = false;
	for (auto i : a) {
		if (flag)
			break;
		ll st = 1;
		while (i - st >= a[0] || i + st <= a.back()) {
			if (s.find(i - st) != s.end()) {
				if (s.find(i + st) != s.end()) {
					ans = { i - st, i, i + st };
					flag = true;
					break;
				}
				else {
					if (ans.size() < 2)
						ans = { i - st, i };
				}
			}
			else if (s.find(i + st) != s.end()) {
				if (ans.size() < 2)
					ans = { i, i + st};
			}
			st *= 2;
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i << " ";
}