#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

bool solve(int n, int r, int R) {
	if (r > R) return n <= 0;
	if (2 * r > R) return n <= 1;
	if (2 * r == R) return n <= 2;

	double ang = asin((double)(r) / (double)(R - r));
	return ang * (double)(n) < 2.0 * acos(0.0) + 1e-10;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, R, r;
	scanf("%d%d%d", &n, &R, &r);
	if (solve(n, r, R))
		cout << "YES" << endl; else
		cout << "NO" << endl;
	return 0;
}