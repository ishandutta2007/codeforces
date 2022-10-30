#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
string s[maxN], r;
int a[maxN], b[maxN];
int n, m, id;
char t[50];

int getMin() {
	int value = a[id] + b[n - 1];
	vector < int > needed;
	for (int i = 0; i < n; ++i) {
		if (i == id) {
			continue;
		}
		if (s[i] > s[id] && value - a[i] >= 0) {
			needed.push_back(value - a[i]);
		}
		if (s[i] < s[id] && value - a[i] - 1 >= 0) {
			needed.push_back(value - a[i] - 1);
		}
	}
	sort(needed.begin(), needed.end());
	int index = 0;
	int win = 0;
	for (int i = 0; i + 1 < n; ++i) {
		while (index < needed.size() && needed[index] < b[i]) {
			++index;
		}
		if (index < needed.size()) {
			++win;
			++index;
		}
	}
	return n - win;
}

int getMax() {
	int value = a[id] + b[0];
	vector < int > needed;
	for (int i = 0; i < n; ++i) {
		if (i == id) {
			continue;
		}
		if (s[i] > s[id]) {
			needed.push_back(value - a[i] + 1);
		}
		if (s[i] < s[id]) {
			needed.push_back(value - a[i]);
		}
	}
	sort(needed.begin(), needed.end());
	int index = 1;
	int win = 0;
	for (int i = 0; i < needed.size(); ++i) {
		while (index < n && b[index] < needed[i]) {
			++index;
		}
		if (index < n) {
			++win;
			++index;
		}
	}
	return win + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		memset(t, 0, sizeof(t));
		scanf("%s", &t);
		s[i] = t;
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	sort(b, b + n);
	{
		memset(t, 0, sizeof(t));
		scanf("%s", &t);
		r = t;
	}

	id = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == r) {
			id = i;
			break;
		}
	}

	printf("%d %d\n", getMin(), getMax());

	
	return 0;
}