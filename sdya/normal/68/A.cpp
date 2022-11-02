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

	int p1, p2, p3, p4;
	int a, b;
	cin >> p1 >> p2 >> p3 >> p4;
	cin >> a >> b;
	int p = min(min(p1, p2), min(p3, p4));
	int res = 0;
	for (int i = a; i < p && i <= b; ++i) {
		++res;
	}
	cout << res << endl;

	return 0;
}