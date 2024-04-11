#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
int A[100100], B[100100], C[100100];
vector<int> clr[100100], vtx[100100];
vector<int> uf[100100];

map<pair<int, int>, int > sol;

int f(int c, int v)
{
	return lower_bound(vtx[c].begin(), vtx[c].end(), v) - vtx[c].begin();
}

int root(int u, int p)
{
	return (uf[u][p] < 0) ? p : (uf[u][p] = root(u, uf[u][p]));
}

void join(int u, int p, int q)
{
	p = root(u, p);
	q = root(u, q);
	if (p == q) return;

	uf[u][p] += uf[u][q];
	uf[u][q] = p;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", A + i, B + i, C + i);
		--C[i];
		--A[i]; --B[i];

		clr[A[i]].push_back(C[i]);
		clr[B[i]].push_back(C[i]);
		vtx[C[i]].push_back(A[i]);
		vtx[C[i]].push_back(B[i]);
	}

	for (int i = 0; i < N; ++i) {
		sort(clr[i].begin(), clr[i].end());
		clr[i].erase(unique(clr[i].begin(), clr[i].end()), clr[i].end());
	}

	for (int i = 0; i < M; ++i) {
		sort(vtx[i].begin(), vtx[i].end());
		vtx[i].erase(unique(vtx[i].begin(), vtx[i].end()), vtx[i].end());

		for (int j = 0; j < vtx[i].size(); ++j) uf[i].push_back(-1);
		vtx[i].push_back(1001001001);
	}

	for (int i = 0; i < M; ++i) {
		join(C[i], f(C[i], A[i]), f(C[i], B[i]));
	}

	int Q, x, y;
	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", &x, &y);
		--x; --y;

		if (clr[x].size() > clr[y].size() || (clr[x].size() == clr[y].size() && x > y)) {
			swap(x, y);
		}

		int ret;

		if (sol.count(make_pair(x, y))) {
			ret = sol[make_pair(x, y)];
		} else {
			ret = 0;

			for (int j = 0; j < clr[x].size(); ++j) {
				int c = clr[x][j], x2 = f(c, x), y2 = f(c, y);
				if (vtx[c][y2] != y) continue;
				if (root(c, x2) == root(c, y2)) ++ret;
			}

			sol.insert(make_pair(make_pair(x, y), ret));
		}

		printf("%d\n", ret);
	}

	return 0;
}