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

const int maxN = 1100000;
int n, x[maxN];
int a, b;

pair < int, int > r[maxN], q[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	n = unique(x, x + n) - x;
	scanf("%d%d", &a, &b);
	/*n = 100000;
	for (int i = 0; i < n; ++i) {
		x[i] = i + 2;
	}
	a = 1000 * 1000000;
	b = 999 * 1000000;*/

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int value = a - (a % x[i]);
		if (value >= b) {
			r[cnt++] = make_pair(value, x[i]);
		}
	}
	int res = 0;
	while (a != b) {
		int minValue = 1000000000;
		for (int i = 0; i < cnt; ++i) {
			if (r[i].first < minValue) {
				minValue = r[i].first;
			}
		}
		++res;
		if (minValue >= a) {
			--a;
		} else {
			a = minValue;
		}
		for (int i = 0; i < cnt; ++i) {
			if (r[i].first > a) {
				int value = a - (a % r[i].second);
				if (value >= b) {
					r[i].first = value;
				} else {
					swap(r[i], r[cnt - 1]);
					--cnt;
					--i;
				}
			}
		}
	}
	printf("%d\n", res);

	return 0;
}