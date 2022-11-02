#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
//#define int long long
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>s(n);
	vector<int>c(k);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i]--;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		c[i]--;
	}
	vector<int>ch(m, -1);
	for (int i = 0; i < n; i++) {
		if (ch[s[i]] == -1 || a[ch[s[i]]] < a[i]) {
			ch[s[i]] = i;
		}
	}
	int ans = k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			if (ch[j] == c[i]) {
				ans--;
			}
		}
	}
	cout << ans;
	return 0;
}