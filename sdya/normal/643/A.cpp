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

const int maxN = 5100;
int a[maxN], n;
int cnt[maxN];

int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		--a[i];
	}

	for (int i = 0; i < n; ++i) {
		int mx = -1, index = -1;
		for (int j = 0; j < n; ++j) {
			cnt[j] = 0;
		}

		for (int j = i; j < n; ++j) {
			++cnt[a[j]];

			if (cnt[a[j]] > mx) {
				mx = cnt[a[j]];
				index = a[j];
			} else if (cnt[a[j]] == mx && a[j] < index) {
				index = a[j];
			}

			++res[index];
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}