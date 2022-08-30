#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
vector<pair<int, int>> graph[1010];
pair<int, int> lvs[1010];

void visit1(int p, int rt = -1)
{
	if (graph[p].size() == 1) {
		lvs[p] = make_pair(p, -1);
		for (auto e : graph[p]) {
			int q = e.first;
			if (q == rt) continue;
			visit1(q, p);
		}
	} else {
		lvs[p] = make_pair(-1, -1);
		for (auto e : graph[p]) {
			int q = e.first;
			if (q == rt) continue;
			visit1(q, p);
			if (lvs[p].first == -1) lvs[p].first = lvs[q].first;
			else lvs[p].second = lvs[q].first;
		}
		//printf("%d: %d %d\n", p, lvs[p].first, lvs[p].second);
	}
}

vector<pair<pair<int, int>, int>> ans;
int seed;

int visit2(int p, int rt = -1)
{
	int dim = 0;
	for (auto e : graph[p]) {
		int q = e.first;
		if (q == rt) continue;

		int ew = e.second - visit2(q, p);
		if (graph[q].size() == 1) {
			ans.push_back({{ seed, q }, ew });
		} else {
			int u = lvs[q].first, v = lvs[q].second;
			ans.push_back({{ seed, u }, ew / 2 });
			ans.push_back({{ seed, v }, ew / 2 });
			ans.push_back({{ u, v }, -ew / 2 });
		}
		dim += e.second;
	}

	if (rt == -1) return dim;

	return dim;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		graph[x].push_back({y, w});
		graph[y].push_back({x, w});
	}
	for (int i = 0; i < N; ++i) if (graph[i].size() == 2) {
		if (graph[i][0].second != graph[i][1].second) {
			puts("NO");
			return 0;
		}
	}
	for (int i = 0; i < N; ++i) if (graph[i].size() == 1) {
		seed = i;
		break;
	}
	visit1(seed);
	visit2(seed);

	puts("YES");
	printf("%d\n", ans.size());
	for (auto a : ans) printf("%d %d %d\n", a.first.first + 1, a.first.second + 1, a.second);
	return 0;
}