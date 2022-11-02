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

const int maxN = 3100000;
int n, k, a[maxN];
int nt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	int mn = maxN;
	for (int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		++a[value];
		mn = min(mn, value);
	}
	memset(nt, -1, sizeof(nt));
	for (int i = maxN - 2; i >= 0; --i) {
		if (a[i]) {
			nt[i] = i;
		} else {
			nt[i] = nt[i + 1];
		}
	}


	for (int d = mn; d >= 1; --d) {
		bool isOk = true;
		if (d <= k) {
			printf("%d\n", d);
			return 0;
		}
		for (int i = d; ; i += d) {
			int j = nt[i + k + 1];
			if (j == -1) {
				break;
			}
			if (j < i + d) {
				isOk = false;
				break;
			}
		}
		if (isOk) {
			printf("%d\n", d);
			return 0;
		}
	}


	return 0;
}