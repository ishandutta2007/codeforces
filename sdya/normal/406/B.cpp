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

const int maxN = 1100000;
int n, a[maxN];

int used[maxN], cnt[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int s = 1000000;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++used[a[i]];
		++used[s + 1 - a[i]];
		++cnt[a[i]];
	}

	vector < int > p;
	vector < int > y;

	int needed = 0;
	for (int i = 1; i < s + 1 - i; ++i) {
		if (used[i] == 0 && used[s + 1 - i] == 0) {
			p.push_back(i);
			continue;
		}
		if (used[i] == 2 && used[s + 1 - i] == 2) {
			++needed;
			continue;
		}
		if (cnt[i] == 0) {
			y.push_back(i);
		} else {
			y.push_back(s + 1 - i);
		}
	}

	for (int i = 0; i < needed; ++i) {
		y.push_back(p[i]);
		y.push_back(s + 1 - p[i]);
	}
	sort(y.begin(), y.end());
	printf("%d\n", y.size());
	for (int i = 0; i < y.size(); ++i) {
		printf("%d ", y[i]);
	}
	printf("\n");


	/*long long S = 0;
	for (int i = 0; i < n; ++i) {
		S += a[i] - 1;
	}
	for (int i = 0; i < y.size(); ++i) {
		S -= (s - y[i]);
	}
	cerr << S << endl;*/

	return 0;
}