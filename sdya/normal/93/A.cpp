#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	--a;
	--b;

	long long x1 = a / m;
	long long y1 = a % m;
	long long x2 = b / m;
	long long y2 = b % m;

	if (b == n - 1) {
		y2 = m - 1;
	}
	
	if (x1 == x2) {
		cout << 1 << endl;
		return 0;
	}

	int res = 2;
	long long l = x1 + 1;
	if (y1 == 0) {
		--l;
		--res;
	}
	long long r = x2 - 1;
	if (y2 == m - 1) {
		++r;
		--res;
	}
	if (l <= r) {
		++res;
	}

	if (res == 3 && y1 == y2 + 1) {
		res = 2;
	}
	cout << res << endl;
	
	return 0;
}