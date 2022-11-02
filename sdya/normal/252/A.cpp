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
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int value = 0;
		for (int j = i; j < n; ++j) {
			value ^= a[j];
			res = max(res, value);
		}
	}
	cout << res;

	return 0;
}