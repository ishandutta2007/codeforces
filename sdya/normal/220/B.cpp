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

const int maxN = 110000;
int n, m, a[maxN];
vector < int > cnt[maxN];
int l[maxN], r[maxN];
int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] < maxN) {
			cnt[a[i]].push_back(i);
		}
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if (cnt[i].size() < i) {
			continue;
		}

		for (int j = 1; j <= m; ++j) {
			int a = lower_bound(cnt[i].begin(), cnt[i].end(), l[j]) - cnt[i].begin();
			int b = upper_bound(cnt[i].begin(), cnt[i].end(), r[j]) - cnt[i].begin();
			if (b - a == i) {
				++res[j];
			}
		}
	}

	for (int i = 1; i <= m; ++i) {
		printf("%d\n", res[i]);
	}


	return 0;
}