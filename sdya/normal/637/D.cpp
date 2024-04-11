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

const int maxN = 210000;
int n, m, s, d;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (n == 0) {
		printf("RUN %d\n", m);
		return 0;
	}
	vector < pair < int, int > > b;
	int start = a[0], ending = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] - ending < s + 2) {
			ending = a[i];
			continue;
		}
		b.push_back(make_pair(start - 1, ending + 1));
		start = ending = a[i];
	}
	b.push_back(make_pair(start - 1, ending + 1));
	vector < pair < int, int > > actions;
	int pos = 0;
	for (int i = 0; i < b.size(); ++i) {
		if (b[i].second - b[i].first > d) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
		if (b[i].first - pos < s) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
		actions.push_back(make_pair(1, b[i].first - pos));
		actions.push_back(make_pair(2, b[i].second - b[i].first));
		pos = b[i].second;
	}

	if (pos < m) {
		actions.push_back(make_pair(1, m - pos));
	}
	for (int i = 0; i < actions.size(); ++i) {
		if (actions[i].first == 1) {
			printf("RUN %d\n", actions[i].second);
		} else {
			printf("JUMP %d\n", actions[i].second);
		}
	}

	return 0;
}