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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
signed main() {
	int n;
	cin >> n;
	vector<string>a(n);
	vector<pair<int, int>>b(n);


	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vector<int>d(a[i].size() + 1);
		if (a[i][0] == ')') {
			d[0] = 1;
		}
		else {
			d[0] = -1;
		}
		d[a[i].size()] = 0;
		for (int j = 1; j < a[i].size(); j++) {
			if (a[i][j] == ')') {
				d[j] = d[j - 1] + 1;
			}
			else {
				d[j] = d[j - 1] - 1;
			}
		}

		vector<int>d2(a[i].size() + 1);
		if (a[i][a[i].size() - 1] == '(') {
			d2[a[i].size() - 1] = 1;
		}
		else {
			d2[a[i].size() - 1] = -1;
		}
		for (int j = (int)a[i].size() - 2; j> -1; j--) {
			if (a[i][j] == '(') {
				d2[j] = d2[j + 1] + 1;
			}
			else {
				d2[j] = d2[j + 1] - 1;
			}
		}
		int mx = 0;
		int mi = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (mi < d[j] && a[i][j] == ')') {
				mi = d[j];
			}
		}
		for (int j = (int)a[i].size() - 1; j > -1; j--) {
			if (mx < d2[j] && a[i][j] == '(') {
				mx = d2[j];
			}
		}
		mx = abs(mx);
		mi = abs(mi);
		b[i].first = mi;
		b[i].second = mx;
	}
	vector<int>v1(1000000);
	vector<int>v2(1000000);
	int z = 0;
	for (int i = 0; i < n; i++) {
		if (b[i].first == 0 && b[i].second == 0) {
			z++;
			continue;
		}
		if (b[i].first == 0) {
			v2[b[i].second]++;
		}
		if (b[i].second == 0) {
			v1[b[i].first]++;
		}
	}
	int ans = z / 2;
	for (int i = 1; i < 1000000; i++) {
		ans += min(v1[i], v2[i]);
	}
	cout << ans;
	return 0;
}