#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);

	if (2 * h < d) {
		cout << -1 << endl;
		return 0;
	}

	if (d == 1 && n > 2) {
		cout << -1 << endl;
		return 0;
	}

	int r = h;
	int l = d - h;

	for (int i = 1; i <= r; ++i) {
		printf("%d %d\n", i, i + 1);
	}

	vector<int> rst;
	for (int i = r + 2; i <= n; ++i) {
		rst.push_back(i);
	}

	vector<int> gl;
	gl.push_back(1);
	for (int i = 0; i < l; ++i) {
		gl.push_back(rst[i]);
	}

	for (int i = 0; i < l; ++i) {
		printf("%d %d\n", gl[i], gl[i + 1]);
	}

	for (int i = l; i < rst.size(); ++i) {
		printf("%d %d\n", r, rst[i]);
	}

	return 0;
}