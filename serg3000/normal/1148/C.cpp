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
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("no-stack-protector")
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<pair<int, int>>ans;
	int i = 1;
	while (i != n - 1) {
		if (a[i] != i) {
			if (i >= n / 2) {
				ans.push_back({ i, 0 });
				swap(a[i], a[0]);
				if (a[0] != 0) {
					if (a[0] >= n / 2) {
						ans.push_back({ a[0], 0 });
						swap(a[0], a[a[0]]);
					}
					else {
						ans.push_back({ 0, n - 1 });
						swap(a[0], a[n - 1]);
						ans.push_back({ a[n - 1], n - 1 });
						swap(a[n - 1], a[a[n - 1]]);
					}
				}
			}
			else {
				ans.push_back({ i, n - 1 });
				swap(a[i], a[n - 1]);
				if (a[n - 1] != n - 1) {
					if (a[n - 1] < n / 2) {
						ans.push_back({ a[n - 1], n - 1 });
						swap(a[n - 1], a[a[n - 1]]);
					}
					else {
						ans.push_back({ 0, n - 1 });
						swap(a[0], a[n - 1]);
						ans.push_back({ a[0], 0 });
						swap(a[0], a[a[0]]);
					}
				}
			}
		}
		else {
			i++;
		}
	}
	if (a[0] != 0) {
		ans.push_back({ 0, n - 1 });
		swap(a[0], a[n - 1]);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
	}
	return 0;
}