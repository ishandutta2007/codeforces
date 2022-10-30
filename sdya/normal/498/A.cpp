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

	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long u = a * x1 + b * y1 + c;
		long long v = a * x2 + b * y2 + c;

		u = (u > 0 ? 1 : -1);
		v = (v > 0 ? 1 : -1);
		if (u * v == -1) {
			++res;
		}
	}
	cout << res << endl;

	
	return 0;
}