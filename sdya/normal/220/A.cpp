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

bool isOk(vector < int > a) {
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (isOk(a)) {
		printf("YES\n");
		return 0;
	}

	int x = -1, y = -1;
	for (int i = 0; i + 1 < n; ++i) {
		if (a[i] > a[i + 1]) {
			x = i;
			break;
		}
	}

	for (int i = n - 1; i > 0; --i) {
		if (a[i] < a[i - 1]) {
			y = i;
			break;
		}
	}

	if (x != -1) {
		while (x - 1 >= 0 && a[x] == a[x - 1]) {
			--x;
		}
	}

	if (y != -1) {
		while (y + 1 < n && a[y] == a[y + 1]) {
			++y;
		}
	}

	if (x == -1 || y == -1) {
		printf("NO\n");
		return 0;
	}

	swap(a[x], a[y]);
	if (isOk(a)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}