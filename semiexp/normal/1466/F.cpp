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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
vector<int> X[505050];

bool fox[505050];
vector<int> tree[505050];

int uf[505050];

int root(int p) {
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
bool join(int p, int q) {
	p = root(p);
	q = root(q);
	if (p == q) return false;
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

void propagate(int p) {
	if (fox[p]) return;
	fox[p] = true;
	for (int q : tree[p]) {
		propagate(q);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			int x;
			scanf("%d", &x);
			X[i].push_back(x - 1);
		}
	}
	for (int i = 0; i < M; ++i) {
		fox[i] = false;
		uf[i] = -1;
	}

	vector<int> S;
	for (int i = 0; i < N; ++i) {
		if (X[i].size() == 1) {
			int x = X[i][0];
			if (fox[x]) continue;
			propagate(x);
			S.push_back(i);
		} else {
			int x = X[i][0], y = X[i][1];
			if (fox[x] && fox[y]) continue;
			if (!join(x, y)) continue;

			tree[x].push_back(y);
			tree[y].push_back(x);
			if (fox[x] || fox[y]) {
				propagate(x);
				propagate(y);
			}
			S.push_back(i);
		}
	}

	i64 t = 1;
	for (int i = 0; i < S.size(); ++i) t = t * 2 % MOD;

	printf("%lld %d\n", t, (int)S.size());
	for (int i = 0; i < S.size(); ++i) printf("%d%c", S[i] + 1, i + 1 == S.size() ? '\n' : ' ');
	return 0;
}