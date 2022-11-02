#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector < int > cnt(6000, 0);
	int mx = *max_element(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		++cnt[a[i]];
	}
	deque < int > d;
	d.push_back(mx);
	int res = 1;
	for (int i = mx - 1; i >= 0; --i) {
		if (cnt[i] >= 2) {
			d.push_front(i);
			d.push_back(i);
		} else if (cnt[i] == 1) {
			d.push_back(i);
		}
	}
	cout << d.size() << endl;
	for (int i = 0; i < d.size(); ++i) {
		cout << d[i] << " ";
	}
	cout << endl;

	return 0;
}