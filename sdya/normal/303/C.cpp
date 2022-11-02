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
const int maxL = 1010000;
int a[maxN], n, k;
int used[maxL];

int d[maxL];
int v[maxL];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			++d[a[j] - a[i]];
		}
	}
	for (int i = 1; i < maxL; ++i) {
		v[i] = 0;
		for (int j = i; j < maxL; j += i) {
			v[i] += d[j];
		}
	}

	for (int i = max(1, n - k - 1); ; ++i) {
		{
			if (k == 0) {
				if (v[i] > 0) {
					continue;
				}
			}
			if (k == 1) {
				if (v[i] > 1) {
					continue;
				}
			}
			if (k == 2) {
				if (v[i] > 3) {
					continue;
				}
			}
			if (k == 3) {
				if (v[i] > 6) {
					continue;
				}
			}
			if (k == 4) {
				if (v[i] > 10) {
					continue;
				}
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			int v = a[j] % i;
			if (used[v] == i) {
				++cnt;
				if (cnt > k) {
					break;
				}
			} else {
				used[v] = i;
			}
		}
		if (cnt <= k) {
			printf("%d\n", i);
			return 0;
		}
	}


	return 0;
}