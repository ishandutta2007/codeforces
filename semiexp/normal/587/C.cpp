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

int N, M, Qu;
vector<int> graph[101010];
vector<int> lives[101010];
int mn[101010][17][10], depth[101010];
int upp[101010][17];
const int INFT = 2100000000;

void dfs(int p, int rt, int d = 0)
{
	upp[p][0] = rt;
	depth[p] = d;
	for (int i = 1; i < 17; ++i) {
		if (upp[p][i - 1] == -1) upp[p][i] = -1;
		else upp[p][i] = upp[upp[p][i - 1]][i - 1];
	}
	for (int q : graph[p]) if (q != rt) {
		dfs(q, p, d + 1);
	}
}
void dfs2(int p, int rt)
{
	sort(lives[p].begin(), lives[p].end());
	for (int i = 0; i < 10; ++i) {
		mn[p][0][i] = (i < lives[p].size() ? lives[p][i] : INFT);
	}
	priority_queue<int> Q;
	for (int i = 1; i < 17; ++i) {
		for (int j = 0; j < 10; ++j) Q.push(mn[p][i - 1][j]);
		if (upp[p][i - 1] != -1) {
			int p2 = upp[p][i - 1];
			for (int j = 0; j < 10; ++j) Q.push(mn[p2][i - 1][j]);
		}
		while (Q.size() > 10) Q.pop();
		for (int j = 9; j >= 0; --j) {
			mn[p][i][j] = Q.top(); Q.pop();
		}
	}

	for (int q : graph[p]) if (q != rt) dfs2(q, p);
}

void regs(priority_queue<int> &Q, int p, int d)
{
//	printf("%d %d: ", p, d);
//	for (int i = 0; i < 10; ++i) printf(" %d", mn[p][d][i]);
//	puts("");
	for (int i = 0; i < 10; ++i) Q.push(-mn[p][d][i]);
}

int main()
{
	scanf("%d%d%d", &N, &M, &Qu);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < M; ++i) {
		int c;
		scanf("%d", &c);
		--c;
		lives[c].push_back(i + 1);
	}
	dfs(0, -1);
	dfs2(0, -1);

	for (int i = 0; i < Qu; ++i) {
		int u, v, a;
		scanf("%d%d%d", &u, &v, &a);
		--u; --v;

		priority_queue<int> Q;
		if (depth[u] > depth[v]) swap(u, v);
		for (int j = 16; j >= 0; --j) if (depth[u] <= depth[v] - (1 << j)) {
			regs(Q, v, j);
			v = upp[v][j];
		}
		if (u != v) {
			for (int j = 16; j >= 0; --j) if (upp[u][j] != upp[v][j]) {
				regs(Q, u, j);
				regs(Q, v, j);
				u = upp[u][j];
				v = upp[v][j];
			}
			regs(Q, u, 0);
			regs(Q, v, 0);
			u = upp[u][0];
			v = upp[v][0];
		}
		regs(Q, u, 0);

		vector<int> ans;
		for (int j = 0; j < a; ++j) {
			int t = -Q.top(); Q.pop();
			if (t != INFT) ans.push_back(t);
		}
		printf("%d", ans.size());
		for (int j : ans) printf(" %d", j);
		puts("");
	}

	return 0;
}