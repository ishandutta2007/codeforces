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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, q;
int a[maxN], v[maxN];
int l[maxN], r[maxN];

void removeR(int value, set < int > &common) {
	--r[value];
	if (r[value] == 0) {
		common.erase(value);
	}
}

void addL(int value, set < int > &common) {
	++l[value];
	if (l[value] == 1 && r[value] > 0) {
		common.insert(value);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int m = *max_element(a, a + n);

	if (count(a, a + n, 0) == n) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ", q);
		}
		printf("\n");
		return 0;
	}

	bool hasmax = (m == q);
	if (count(a, a + n, 0) == 0 && !hasmax) {
		printf("NO\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] != 0) {
			v[i] = a[i];
		}
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == 0 && v[i - 1] != 0) {
			v[i] = v[i - 1];
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] == 0 && v[i] == 0 && v[i + 1] != 0) {
			v[i] = v[i + 1];
		}
	}

	set < int > common;

	for (int i = 0; i < n; ++i) {
		++r[a[i]];
	}


	int mindex = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0) {
			removeR(a[i], common);

			if (i > 0 && a[i - 1] != 0) {
				addL(a[i - 1], common);
			}
		} else {
			if (i > 0 && a[i - 1] != 0) {
				addL(a[i - 1], common);
			}

			if (common.empty() || *common.rbegin() < q) {
				mindex = i;
			}
		}
	}

	if (!hasmax) {
		if (mindex == -1) {
			printf("NO\n");
			return 0;
		}
		v[mindex] = q;
	}

	common.clear();
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));

	for (int i = 0; i < n; ++i) {
		a[i] = v[i];
		++r[a[i]];
	}

	for (int i = 0; i < n; ++i) {
		removeR(a[i], common);

		if (i > 0) {
			addL(a[i - 1], common);
		}

		if (!common.empty() && a[i] < *common.rbegin()) {
			cout << "NO" << endl;
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}