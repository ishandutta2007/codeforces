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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;

int n, m;
long long l[maxN], r[maxN];
long long d[maxN];

int order[maxN];

bool comp(int x, int y) {
	return d[x] < d[y];
}

int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &l[i], &r[i]);
		res[i] = -1;
	}

	for (int i = 0; i < m; ++i) {
		scanf("%I64d", &d[i]);
		order[i] = i;
	}
	sort(order, order + m, comp);

	vector < pair < pair < long long, long long >, int > > p;
	for (int i = 1; i < n; ++i) {
		long long u = l[i] - r[i - 1];
		long long v = r[i] - l[i - 1];
		p.push_back(make_pair(make_pair(u, v), i - 1));
	}

	sort(p.begin(), p.end());

	set < pair < long long, int > > S;
	int index = 0;
	for (int i = 0; i < m; ++i) {
		int v = order[i];
		while (index < p.size() && p[index].first.first <= d[v]) {
			S.insert(make_pair(p[index].first.second, p[index].second));
			++index;
		}

		while (!S.empty() && S.begin()->first < d[v]) {
			S.erase(S.begin());
		}

		if (!S.empty()) {
			res[S.begin()->second] = v;
			S.erase(S.begin());
		}
	}

	for (int i = 0; i + 1 < n; ++i) {
		if (res[i] == -1) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
	for (int i = 0; i + 1 < n; ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");

	return 0;
}