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

int TC;
int N, M;
int L[505050], R[505050];
vector<int> adj[505050];
bool fox[505050];

int P[505050], Q[505050];
bool paired[505050];

int nonapp(int p) {
	for (int i = 0; i < adj[p].size(); ++i) {
		if (adj[p][i] != i) return i;
	}
	return adj[p].size();
}

vector<int> comp[505050];

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++i) {
			scanf("%d%d", L + i, R + i);
			--L[i]; --R[i];
		}
		for (int i = 0; i < N; ++i) {
			adj[i].clear();
			paired[i] = false;
			adj[i].push_back(i);
			comp[i].clear();
			P[i] = Q[i] = -1;
			fox[i] = false;
		}
		for (int i = 0; i < M; ++i) {
			adj[L[i]].push_back(R[i]);
			adj[R[i]].push_back(L[i]);
		}
		for (int i = 0; i < N; ++i) sort(adj[i].begin(), adj[i].end());
		for (int i = 0; i < N; ++i) {
			fox[i] = adj[i].size() == N;
		}

		vector<int> unfixed;
		for (int i = 0; i < N; ++i) {
			if (!fox[i]) unfixed.push_back(i);
		}

		vector<int> deg(N, 0);
		vector<pair<int, int>> edges;
		for (int p : unfixed) {
			if (paired[p]) continue;
			int q = nonapp(p);
			paired[p] = paired[q] = true;

			edges.push_back({p, q});
			deg[p]++;
			deg[q]++;
		}

		vector<pair<int, int>> edges2;

		for (auto& e : edges) {
			int p = e.first, q = e.second;
			if (deg[p] >= 2 && deg[q] >= 2) {
				--deg[p];
				--deg[q];
			} else {
				edges2.push_back(e);
			}
		}
		for (auto& e : edges2) {
			int p = e.first, q = e.second;
			int base;
			if (deg[p] > deg[q]) base = p;
			else if (deg[p] < deg[q]) base = q;
			else base = min(p, q);

			comp[base].push_back(p + q - base);
		}
		int last = 0;
		for (int p : unfixed) if (comp[p].size() > 0) {
			P[p] = last;
			for (int i = 0; i < comp[p].size(); ++i) P[comp[p][i]] = last + i + 1;

			Q[p] = last + comp[p].size();
			for (int i = 0; i < comp[p].size(); ++i) Q[comp[p][i]] = last + i;

			last += 1 + comp[p].size();
		}

		for (int i = 0; i < N; ++i) if (fox[i]) {
			P[i] = Q[i] = last++;
		}
		for (int i = 0; i < N; ++i) printf("%d%c", P[i] + 1, i == N - 1 ? '\n' : ' ');
		for (int i = 0; i < N; ++i) printf("%d%c", Q[i] + 1, i == N - 1 ? '\n' : ' ');
	}
	return 0;
}