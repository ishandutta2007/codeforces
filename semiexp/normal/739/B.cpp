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

int N, A[202020];
vector<pair<int, int> > graph[202020];
int ans[202020];

priority_queue<i64> *dfs(int p, int rt, i64 dep)
{
	vector<priority_queue<i64> *> V;

	for (auto e : graph[p]) if (e.first != rt) {
		V.push_back(dfs(e.first, p, dep + e.second));
	}

	priority_queue<i64> *merged;
	if (V.size() > 0) {
		int largest = 0;
		for (int i = 1; i < V.size(); ++i) {
			if (V[largest]->size() < V[i]->size()) largest = i;
		}
		merged = V[largest];
		V[largest] = V[V.size() - 1];
		V.pop_back();

		for (int i = 0; i < V.size(); ++i) {
			auto a = V[i];
			while (!a->empty()) {
				merged->push(a->top());
				a->pop();
			}
		}
	} else {
		merged = new priority_queue<i64>();
	}
	while (!merged->empty() && merged->top() > dep) {
		merged->pop();
	}
	ans[p] = merged->size();
	merged->push(dep - A[p]);
	return merged;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", A + i);
	for (int i = 1; i < N; ++i) {
		int p, w;
		scanf("%d%d", &p, &w);
		--p;
		graph[p].push_back({ i, w });
		graph[i].push_back({ p, w });
	}
	dfs(0, -1, 0);
	for (int i = 0; i < N; ++i) printf("%d%c", ans[i], i == N - 1 ? '\n' : ' ');

	return 0;
}