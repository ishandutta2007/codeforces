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
	for (int i = 1; i <= 2000; ++i) {
		vector < bool > can(n, false);
		if (a[0] >= i) {
			can[0] = true;
		}
		for (int j = 1; j < n; ++j) {
			if (a[j] < i) {
				continue;
			}
			if (can[j - 1] || (j >= 2 && can[j - 2])) {
				can[j] = true;
			}
		}
		if (can[n - 1]) {
			++res;
		}
	}
	cout << res << endl;


	return 0;
}