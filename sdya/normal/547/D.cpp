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
int n, x[maxN], y[maxN];
int order[maxN];

set < int > sx[maxN], sy[maxN];
set < int > unused;

int res[maxN];

void remove(int v) {
	sx[x[v]].erase(v);
	sy[y[v]].erase(v);
	unused.erase(v);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	//return 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		sx[x[i]].insert(i);
		sy[y[i]].insert(i);
		unused.insert(i);
	}

	while (!unused.empty()) {
		deque < int > q;
		int v = *unused.begin();
		remove(v);
		q.push_back(v);
		int sl = 0, sr = 1;
		while (true) {
			bool update = false;

			int l = q.front();
			{
				set < int > &s = (sl == 0 ? sx[x[l]] : sy[y[l]]);
				if (!s.empty()) {
					int u = *s.begin();
					remove(u);
					q.push_front(u);
					sl = 1 - sl;
					update = true;
				}
			}

			int r = q.back();
			{
				set < int > &s = (sr == 0 ? sx[x[r]] : sy[y[r]]);
				if (!s.empty()) {
					int u = *s.begin();
					remove(u);
					q.push_back(u);
					sr = 1 - sr;
					update = true;
				}
			}

			if (!update) {
				break;
			}
		}

		for (int i = 0; i < q.size(); ++i) {
			res[q[i]] = i % 2;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%c", res[i] == 0 ? 'r' : 'b');
	}
	printf("\n");



	return 0;
}