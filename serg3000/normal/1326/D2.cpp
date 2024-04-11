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
mt19937 rnd(time(nullptr));
#define int long long
#define all(v) v.begin(), v.end()
signed main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		string ss, s;
		cin >> ss;
		int z = -2;
		for (int i = 0; i < (int)ss.size(); i++) {
			if (ss[i] != ss[(int)ss.size() - i - 1]) {
				z = i;
				break;
			}
		}
		if (z == -2) {
			cout << ss << '\n';
			continue;
		}
		for (int i = z; i <= (int)ss.size() - z - 1; i++) {
			s.push_back(ss[i]);
		}
		int n = s.size();
		vector<int>d1(n);
		
		vector<int>d2(n);
		
		int l = 0, r = -1;
		
		for (int i = 0; i < n; i++) {
			if (i <= r) {
				
				d1[i] = max(min(r - i + 1, d1[l + r - i]), 0ll);
			}
			while (i - d1[i] >= 0 && i + d1[i] < n) {
				
				if (s[i + d1[i]] == s[i - d1[i]]) {
					d1[i]++;
				}
				else {
					break;
				}
			}
			
			if (i + d1[i] - 1 >= r) {
				l = i - d1[i] + 1;
				r = i + d1[i] - 1;
			}
		}
		l = 0; r = -1;
		
		for (int i = 0; i < n; i++) {
			if (i <= r) {
				d2[i] = max(min(r - i + 1, d2[l + r - i + 1]), 0ll);
			}
			while (i - 1 - d2[i] >= 0 && i + d2[i] < n) {
				if (s[i + d2[i]] == s[i - 1 - d2[i]]) {
					d2[i]++;
				}
				else {
					break;
				}
			}
			if (i + d2[i] - 1 > r) {
				r = i + d2[i] - 1;
				l = i - d2[i];
			}
		}
		int mx1 = 0, mx2 = 0, ima1, ima2;
		for (int i = 0; i < n; i++) {
			if (d1[i] == i + 1) {
				if (mx1 < i + 1) {
					ima1 = i;
				}
				mx1 = max(mx1, i + 1);
			}
			if (d1[i] == n - i) {
				if (mx1 < n - i) {
					ima1 = i;
				}
				mx1 = max(mx1, n - i);
			}
		}
		for (int i = 1; i < n; i++) {
			if (d2[i] == i) {
				if (mx2 < i) {
					mx2 = i;
					ima2 = i;
				}
			}
		}
		for (int i = 1; i < n; i ++) {
			if (d2[i] == n - i) {
				if (mx2 < n - i) {
					mx2 = n - i;
					ima2 = i;
				}
			}
		}
		string ans;
		for (int i = 0; i < z; i++) {
			ans.push_back(ss[i]);
		}
		if (mx1 > mx2) {
			if (ima1 >= n / 2) {
				for (int i = n - 1; i >= ima1; i--) {
					ans.push_back(s[i]);
				}
				for (int i = ima1 + 1; i < n; i++) {
					ans.push_back(s[i]);
				}
			}
			else {
				for (int i = 0; i <= ima1; i++) {
					ans.push_back(s[i]);
				}
				for (int i = ima1 - 1; i > -1; i--) {
					ans.push_back(s[i]);
				}
				
			}
		}
		else {
			if (ima2 >= n / 2 + 1) {
				for (int i = n - 1; i >= ima2; i--) {
					ans.push_back(s[i]);
				}
				for (int i = ima2; i < n; i++) {
					ans.push_back(s[i]);
				}
			}
			else {
				for (int i = 0; i <= ima2 - 1; i++) {
					ans.push_back(s[i]);
				}
				for (int i = ima2 - 1; i > -1; i--) {
					ans.push_back(s[i]);
				}
			}
		}
		for (int i = z - 1; i > -1; i--) {
			ans.push_back(ss[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}