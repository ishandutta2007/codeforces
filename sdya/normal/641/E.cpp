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
int n;
int a[maxN], t[maxN], x[maxN], id[maxN];

vector < vector < int > > f, ft;

void update(vector < int > &t, int k, int delta) {
	for (int i = k; i < t.size(); i |= (i + 1)) {
		t[i] += delta;
	}
}

int get(vector < int > &t, int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < int > b;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i], &t[i], &x[i]);
		b.push_back(x[i]);
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	f.assign(b.size(), vector < int > ());
	ft.assign(b.size(), vector < int > ());

	for (int i = 0; i < n; ++i) {
		id[i] = lower_bound(b.begin(), b.end(), x[i]) - b.begin();
		f[id[i]].push_back(t[i]);
	}

	for (int i = 0; i < f.size(); ++i) {
		sort(f[i].begin(), f[i].end());
		f[i].resize(unique(f[i].begin(), f[i].end()) - f[i].begin());

		ft[i].assign(f[i].size(), 0);
	}

	for (int i = 0; i < n; ++i) {
		int index = lower_bound(f[id[i]].begin(), f[id[i]].end(), t[i]) - f[id[i]].begin();
		if (a[i] == 1) {
			update(ft[id[i]], index, +1);
		} else if (a[i] == 2) {
			update(ft[id[i]], index, -1);
		} else {
			int res = get(ft[id[i]], index);
			printf("%d\n", res);
		}
	}

	return 0;
}