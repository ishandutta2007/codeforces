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

const int maxN = 11000;
int n, k;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	k = 100 - k;
	double left_bound = 0, right_bound = 1e5;
	for (int steps = 0; steps < 60; ++steps) {
		double m = (left_bound + right_bound) / 2.0;
		double need = 0, over = 0;
		for (int i = 0; i < n; ++i) {
			if ((double)(a[i]) < m) {
				need += m - a[i];
			} else {
				over -= m - a[i];
			}
		}

		if (over * (double)(k) / 100.0 >= need) {
			left_bound = m;
		} else {
			right_bound = m;
		}
	}
	printf("%.10lf\n", left_bound);

	return 0;
}