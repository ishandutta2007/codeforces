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

const int maxN = 110000;
int n, m, s;
int c[maxN], b[maxN];
pair < int, int > a[maxN];
int f[maxN];
int order[maxN];

bool comp(int x, int y) {
	return b[x] > b[y];
}

bool check(int days) {
	set < pair < int, int > > S;
	int index = 0;
	long long cost = 0;
	for (int i = 0; i < m; ++i) {
		while (index < n && b[order[index]] >= a[i].first) {
			S.insert(make_pair(c[order[index]], order[index]));
			++index;
		}
		if (S.empty()) {
			return false;
		}
		pair < int, int > current = *S.begin();
		S.erase(S.begin());
		cost += current.first;
		for (int j = i; j < m && j < i + days; ++j) {
			f[a[j].second] = current.second + 1;
		}
		i = i + days - 1;
	}
	return cost <= (long long)(s);
}

void print() {
	printf("YES\n");
	for (int i = 0; i < m; ++i) {
		printf("%d ", f[i]);
	}
	printf("\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + m);
	reverse(a, a + m);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		order[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
	}
	sort(order, order + n, comp);

	int left_bound = 0, right_bound = m;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	if (check(left_bound)) {
		print();
	} else if (check(right_bound)) {
		print();
	} else {
		printf("NO\n");
	}


	return 0;
}