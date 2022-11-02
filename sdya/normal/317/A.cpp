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

long long calc(long long x, long long y, long long m) {
	if (x >= m || y >= m) {
		return 0;
	}
	if (x <= 0 && y <= 0) {
		return -1LL;
	}

	if (x > y) {
		swap(x, y);
	}
	if (x >= 0) {
		return 1LL + calc(x + y, y, m);
	}

	long long k = (-x + y) / y;
	return k + calc(x + k * y, y, m);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long x, y, m;
	cin >> x >> y >> m;
	if (x >= m || y >= m) {
		cout << 0 << endl;
		return 0;
	}

	cout << calc(x, y, m) << endl;

	return 0;
}