#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 1024;

struct Road {
	int a, b;
	int w;
	inline Road(int _a = 0, int _b = 0, int _w = 0) : a(_a), b(_b), w(_w) {}
};

int n, m, s, t;
vector<Road> rels[SIZE];
int maxd[SIZE], cost[SIZE];


bool used[SIZE];
int64 dist[SIZE];
struct CmpDist {
	inline bool operator()(int a, int b) const {
		if (dist[a] != dist[b]) return dist[a] < dist[b];
		return a < b;
	}
};
typedef set<int, CmpDist> tSet;
tSet heap;

void MinPath(int root) {
	memset(used, 0, sizeof(used));
	memset(dist, 0x3F, sizeof(dist));
    dist[root] = 0;
	heap.clear();
    for (int i = 0; i<n; i++) heap.insert(i);

	while (heap.size()) {
		int best = *heap.begin();
		if (dist[best] == 0x3F3F3F3F3F3F3F3FLL) break;
		heap.erase(heap.begin());
		used[best] = true;

		for (int i = 0; i<rels[best].size(); i++) {
			const Road &r = rels[best][i];
			if (used[r.b]) continue;
			if (dist[r.b] > dist[best] + r.w) {
				heap.erase(r.b);
				dist[r.b] = dist[best] + r.w;
				heap.insert(r.b);
			}
		}
	}
}

vector<Road> taxi[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	s--;  t--;
	for (int i = 0; i<m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;  b--;
		rels[a].push_back(Road(a, b, c));
		rels[b].push_back(Road(b, a, c));
	}
	for (int i = 0; i<n; i++) scanf("%d%d", &maxd[i], &cost[i]);

	for (int i = 0; i<n; i++) {
		MinPath(i);
		for (int j = 0; j<n; j++) if (i != j && dist[j] <= maxd[i])
			taxi[i].push_back(Road(i, j, cost[i]));
	}

	for (int i = 0; i<n; i++) swap(rels[i], taxi[i]);
	MinPath(s);

	int64 ans = dist[t];
	if (ans > 1000000000000000000LL) printf("-1\n");
	else printf("%I64d\n", ans);

	return 0;
}