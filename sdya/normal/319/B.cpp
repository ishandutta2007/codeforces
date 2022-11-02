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
int a[maxN], n;
int l[maxN], r[maxN];

int p[maxN];

int findSet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = findSet(p[v]);
}

void merge(int u, int v) {
	p[v] = u;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p[i] = i;
		l[i] = r[i] = i;
	}

	vector < int > changed;
	int pos = 1;
	while (pos <= n) {
		int v = findSet(pos);
		int i = r[v] + 1;
		int steps = 0;
		int nvalue = a[v];
		while (i <= n) {
			int value = a[findSet(i)];
			if (nvalue > value) {
				++steps;

				r[v] = r[findSet(i)];
				nvalue = value;
				merge(v, findSet(i));
				i = r[v] + 1;
			} else {
				break;
			}
		}
		if (steps > 0) {
			changed.push_back(v);
		}
		pos = r[v] + 1;
	}

	if (changed.size() == 0) {
		printf("0\n");
		return 0;
	}
	int res = 1;
	while (true) {
		vector < int > nchanged;
		for (int t = 0; t < changed.size(); ++t) {
			int pos = changed[t];
			int v = findSet(pos);
			if (v != pos) {
				continue;
			}

			int i = r[v] + 1;
			int steps = 0;
			int nvalue = a[v];
			while (i <= n) {
				int value = a[findSet(i)];
				if (nvalue > value) {
					++steps;

					r[v] = r[findSet(i)];
					nvalue = value;
					merge(v, findSet(i));
					i = r[v] + 1;
				} else {
					break;
				}
			}
			if (steps > 0) {
				nchanged.push_back(v);
			}
		}
		changed = nchanged;
		if (changed.size() == 0) {
			printf("%d\n", res);
			return 0;
		}
		++res;
	}

	return 0;
}