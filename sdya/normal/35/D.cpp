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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, x;
	cin >> n >> x;
	vector < int > c(n), d(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];

		d[i] = (n - i) * c[i];
	}

	sort(d.begin(), d.end());
	int res = 0;
	for (int i = 0; i < d.size(); ++i) {
		if (x >= d[i]) {
			++res;
			x -= d[i];
		}
	}
	cout << res << endl;

	return 0;
}