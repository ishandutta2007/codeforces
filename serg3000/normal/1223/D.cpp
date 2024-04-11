#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
signed main() {
	int q;
	cin >> q;
	for (int w = 0; w < q; w++) {
		int n;
		cin >> n;
		vector<int>a(n);
		set<int>s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		vector<int>last(n + 100);
		vector<int>f(n + 100);
		for (int i = 0; i < n; i++) {
			last[a[i]] = i;
		}
		for (int i = n - 1; i > -1; i--) {
			f[a[i]] = i;
		}
		int c = (int)s.size();
		vector<int>b;
		for (auto u : s) {
			b.push_back(u);
		}
		int ans = 0;
		int ans2 = 0;
		for (int i = 1; i < c; i++) {
			if (last[b[i - 1]] < f[b[i]]) {
				ans++;
			}
			else {
				ans2 = max(ans2, ans);
				ans = 0;
			}
		}
		ans2 = max(ans2, ans);
		cout << c - 1 - ans2 << '\n';
	}
 
	return 0;
}