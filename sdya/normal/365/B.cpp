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

const int maxN = 110000;
int n, a[maxN], b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i >= 2 && a[i] == a[i - 1] + a[i - 2]) {
			b[i] = 1;
		}
	}

	int res = min(2, n);
	for (int i = n - 1; i >= 0; --i) {
		if (i + 1 < n && b[i]) {
			b[i] = max(b[i], 1 + b[i + 1]);
		}
		if (b[i]) {
			res = max(res, b[i] + 2);
		}
	}
	cout << res << endl;



	return 0;
}