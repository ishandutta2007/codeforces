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

int n, m;

int gcd(int x, int y) {
	if (x == 0 || y == 0) {
		return x + y;
	}
	if (x > y) {
		return gcd(x % y, y);
	} else {
		return gcd(y % x, x);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	if (n == 1) {
		cout << m << endl;
	} else {
		cout << gcd(n - 1, m - 1) + 1 << endl;
	}

	return 0;
}