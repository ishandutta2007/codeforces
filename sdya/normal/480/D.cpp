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

struct State {
	int index;
	bool isIn;
	int value;
	int p;
	State() {}
	State(int index, bool isIn, int value, int p) : index(index), isIn(isIn), value(value), p(p) {}
	bool operator < (const State &other) const {
		if (value < other.value) {
			return true;
		}
		if (value > other.value) {
			return false;
		}

		if (isIn && !other.isIn) {
			return false;
		}
		if (!isIn && other.isIn) {
			return true;
		}

		return p > other.p;
	}
};

const int maxN = 1050;
State states[maxN];
int m;
int d[maxN][maxN];
int n, S, in[maxN], out[maxN], w[maxN], s[maxN], v[maxN];
vector < int > p[maxN];
int a[maxN];

int t[maxN];

int calc(int l, int S) {
	if (d[l][S] != -1) {
		return d[l][S];
	}

	int r = a[l];

	int res = 0;
	int id = states[l].index;
	int nS = min(S - w[id], s[id]);
	if (nS < 0) {
		return d[l][S] = 0;
	}

	for (int i = l + 1; i < r; ++i) {
		if (a[i] < r && w[states[i].index] <= nS) {
			calc(i, nS);
		}
	}
	for (int i = l; i <= r; ++i) {
		t[i] = 0;
	}

	t[l] = t[r] = v[id];
	for (int i = l; i <= r; ++i) {
		if (i > l) {
			t[i] = max(t[i], t[i - 1]);
		}
		if (a[i] < r && w[states[i].index] <= nS) {
			t[a[i]] = max(t[a[i]], d[i][nS] + t[i]);
		}
	}

	return d[l][S] = t[r];
}

int q[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &S);
	m = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d%d", &in[i], &out[i], &w[i], &s[i], &v[i]);
		states[m++] = State(i, true, in[i], out[i]);
		states[m++] = State(i, false, out[i], in[i]);
	}
	sort(states, states + m);

	for (int i = 0; i < m; ++i) {
		p[states[i].index].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		a[i] = m;
	}

	for (int i = 0; i < n; ++i) {
		a[p[i][0]] = p[i][1];
	}
	
	memset(d, -1, sizeof(d));

	q[0] = 0;
	for (int i = 1; i < m; ++i) {
		q[i] = q[i - 1];
		for (int j = 0; j < i; ++j) {
			if (a[j] == i) {
				q[i] = max(q[i], calc(j, S) + q[j]);
			}
		}
	}

	printf("%d\n", q[m - 1]);


	return 0;
}