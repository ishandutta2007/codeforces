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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd(int x, int y) {
	if (x == 0 || y == 0) {
		return x + y;
	}
	if (x > y) {
		return gcd(x % y, y);
	}
	return gcd(y % x, x);
}

int get(int x, int y, int n) {
	return n / (x / gcd(x, y) * y);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x, y, a, b;
	cin >> x >> y >> a >> b;
	cout << get(x, y, b) - get(x, y, a - 1) << endl;

	return 0;
}