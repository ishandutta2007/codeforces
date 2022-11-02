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
	sort(a.rbegin(), a.rend());
	vector < bool > used(n);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		++res;
		for (int j = a[i] - 1; j >= 0; --j) {
			for (int k = n - 1; k > i; --k) {
				if (!used[k] && a[k] >= j) {
					used[k] = true;
					break;
				}
			}
		}
	}
	cout << res << endl;

	return 0;
}