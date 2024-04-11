#define _CRT_SECURE_NO_WARNINGS
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
	int a, b;
	cin >> a >> b;
	int x = 0, y = 0, z = 0;
	for (int i = 1; i <= 6; ++i) {
		int u = abs(a - i);
		int v = abs(b - i);
		if (u < v) {
			++x;
		} else if (u == v) {
			++y;
		} else {
			++z;
		}
	}
	cout << x << " " << y << " " << z << endl;

	return 0;
}