#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int x[maxN], h[maxN];
int n;

int d[maxN][3];

bool isLeft(int index) {
	return x[index] - x[index - 1] > h[index];
}

bool isRight(int index) {
	if (index == n - 1) {
		return true;
	}
	return x[index + 1] - x[index] > h[index];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &h[i]);
	}

	d[0][0] = 1;
	d[0][1] = 0;
	d[0][2] = 0;
	for (int i = 1; i < n; ++i) {
		d[i][2] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		if (isLeft(i)) {
			d[i][0] = max(d[i - 1][0], d[i - 1][2]) + 1;
			if (x[i] - x[i - 1] > h[i - 1] + h[i]) {
				d[i][0] = max(d[i][0], d[i - 1][1] + 1);
			}
		}
		if (isRight(i)) {
			d[i][1] = d[i][2] + 1;
		}
	}

	printf("%d\n", max(d[n - 1][0], max(d[n - 1][1], d[n - 1][2])));


	return 0;
}