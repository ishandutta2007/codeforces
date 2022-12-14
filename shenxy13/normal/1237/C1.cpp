#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <cstdlib>
#define F first
#define S second
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int main() {
	int n;
	scanf("%d", &n);
	iii pos[n];
	for (int i = 0; i < n; ++i) scanf("%d %d %d", &pos[i].F, &pos[i].S.F, &pos[i].S.S);
	priority_queue< iii, vector<iii>, greater<iii> > pq;
	bool taken[n];
	fill_n(taken, n, false);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) pq.push(iii(abs(pos[i].F - pos[j].F) + abs(pos[i].S.F - pos[j].S.F) + abs(pos[i].S.S - pos[j].S.S), ii(i, j)));
	}
	while (!pq.empty()) {
		iii a = pq.top();
		pq.pop();
		if (taken[a.S.F] || taken[a.S.S]) continue;
		taken[a.S.F] = taken[a.S.S] = true;
		printf("%d %d\n", a.S.F + 1, a.S.S + 1);
	}
	return 0;
}