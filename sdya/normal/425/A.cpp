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

const int maxN = 210;
int b[maxN], c[maxN], a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int res = -1000000000;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int s = 0;
			int n1 = 0, n2 = 0;
			for (int k = 0; k < n; ++k) {
				if (k >= i && k <= j) {
					b[n1++] = a[k];
				} else {
					c[n2++] = a[k];
				}
			}
			sort(b, b + n1);
			sort(c, c + n2);
			reverse(c, c + n2);

			for (int k = 0; k < m && k < n1 && k < n2; ++k) {
				if (b[k] < c[k]) {
					b[k] = c[k];
				}
			}
			int cur = 0;
			for (int k = 0; k < n1; ++k) {
				cur += b[k];
			}
			res = max(res, cur);
		}
	}

	cout << res << endl;


	return 0;
}