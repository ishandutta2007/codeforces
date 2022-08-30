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

int N, A[101010], B[101010];
int uf[404040];
int col[202020];
vector<int> graph[404040];
void diffside(int p, int q)
{
	graph[p].push_back(q);
	graph[q].push_back(p);
}

void setcolor(int p, int v)
{
	if (col[p] != 0) return;
	col[p] = v;
	for (int q : graph[p]) setcolor(q, 3 - v);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4 * N; ++i) uf[i] = -1;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", A + i, B + i);
		--A[i]; --B[i];
		diffside(A[i], B[i]);
	}
	for (int i = 0; i < N; ++i) {
		diffside(i * 2, i * 2 + 1);
	}
	for (int i = 0; i < 2 * N; ++i) {
		if (col[i] == 0) setcolor(i, 1);
	}

	for (int i = 0; i < N; ++i) {
		printf("%d %d\n", col[A[i]], col[B[i]]);
	}
	return 0;
}