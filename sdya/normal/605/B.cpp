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

const int maxN = 110000;
int n, m;
int w[maxN], p[maxN];
int order[maxN];
pair < int, int > res[maxN];

bool comp(int x, int y) {
	return make_pair(w[x], -p[x]) < make_pair(w[y], -p[y]);
}

set < pair < int, int > > S;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &w[i], &p[i]);
		order[i] = i;
	}
	sort(order, order + m, comp);

	int cnt = 1;
	for (int i = 0; i < m; ++i) {
		int t = order[i];
		if (p[t] == 0) {
			if (S.empty()) {
				printf("-1\n");
				return 0;
			}
			res[t] = *S.begin();
			S.erase(S.begin());
		} else {
			res[t] = make_pair(1, cnt + 1);
			++cnt;
			for (int j = 2; j < cnt; ++j) {
				if (S.size() < 300000) {
					S.insert(make_pair(j, cnt));
				} else {
					break;
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		printf("%d %d\n", res[i].first, res[i].second);
	}


	return 0;
}