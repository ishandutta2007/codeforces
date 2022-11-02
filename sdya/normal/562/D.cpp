#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, q;
int p[maxN];

int findSet(int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = findSet(p[v]);
}

void merge(int u, int v) {
	u = findSet(u);
	v = findSet(v);
	if (u == v) {
		return;
	}
	if (rand() % 2 == 0) {
		p[u] = v;
	} else {
		p[v] = u;
	}
}

set < pair < int, int > > S;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		S.insert(make_pair(i, i));
		p[i] = i;
	}

	for (int i = 1; i <= q; ++i) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 3) {
			int u = findSet(x);
			int v = findSet(y);
			if (u == v) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else if (t == 1) {
			merge(x, y);
		} else {
			set < pair < int, int > > ::iterator jt = S.upper_bound(make_pair(x, n + 1));
			set < pair < int, int > > ::iterator it = jt;
			--it;
			vector < pair < int, int > > toBeDeleted;
			int l = it->first, r = it->second;
			while (jt != S.end()) {
				if (jt->first > y) {
					break;
				}
				merge(it->first, jt->first);
				toBeDeleted.push_back(*it);
				toBeDeleted.push_back(*jt);
				++it;
				++jt;
			}

			for (int j = 0; j < toBeDeleted.size(); ++j) {
				l = min(l, toBeDeleted[j].first);
				r = max(r, toBeDeleted[j].second);
				S.erase(toBeDeleted[j]);
			}
			S.insert(make_pair(l, r));
		}
	}

	return 0;
}