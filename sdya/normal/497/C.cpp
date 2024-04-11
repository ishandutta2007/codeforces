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

const int maxN = 210000;
int n, m;
int a[maxN], b[maxN];
int c[maxN], d[maxN], w[maxN];

vector < int > order;

bool compA(int x, int y) {
	return make_pair(a[x], b[x]) < make_pair(a[y], b[y]);
}

bool compB(int x, int y) {
	return make_pair(c[x], d[x]) < make_pair(c[y], d[y]);
}

int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		order.push_back(i);
	}

	sort(order.begin(), order.end(), compA);

	scanf("%d", &m);
	vector < int > orderb;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &c[i], &d[i], &w[i]);
		orderb.push_back(i);
	}
	sort(orderb.begin(), orderb.end(), compB);

	set < pair < int, int > > S;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		int u = order[i];

		int l = a[u];
		while (j < m && c[orderb[j]] <= l) {
			S.insert(make_pair(d[orderb[j]], orderb[j]));
			++j;
		}

		while (true) {
			set < pair < int, int > > ::iterator it = S.lower_bound(make_pair(b[u], -1));
			if (it == S.end()) {
				printf("NO\n");
				return 0;
			}
			if (w[it->second] == 0) {
				S.erase(it);
				continue;
			}
			res[u] = it->second;
			--w[it->second];
			break;
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");



	return 0;
}