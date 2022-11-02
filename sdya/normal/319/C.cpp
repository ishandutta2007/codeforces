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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;
int a[maxN], b[maxN];
long long d[maxN];

vector < int > bounds;
vector < long long > sx;
int start = 0;

void add(int index) {
	while (bounds.size() > start) {
		int u = bounds.back();
		long long x = 1LL + (d[index] - d[u]) / (long long)(b[u] - b[index]);
		if (x < sx.back()) {
			bounds.pop_back();
			sx.pop_back();
		} else {
			break;
		}
	}
	if (bounds.size() <= start) {
		bounds.push_back(index);
		sx.push_back(0);
	} else {
		int u = bounds.back();
		long long x = 1LL + (d[index] - d[u]) / (long long)(b[u] - b[index]);
		bounds.push_back(index);
		sx.push_back(x);
	}
}

void update(long long value) {
	for (int i = start + 1; i < bounds.size(); ++i) {
		if (sx[i] <= value) {
			start = i;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}

	d[1] = 0;
	bounds.push_back(1);
	sx.push_back(0);
	start = 0;
	for (int i = 2; i <= n; ++i) {
		update(a[i]);
		d[i] = d[bounds[start]] + (long long)(b[bounds[start]]) * (long long)(a[i]);
		add(i);
	}

	cout << d[n] << endl;


	return 0;
}