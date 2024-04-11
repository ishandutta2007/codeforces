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

int M, A[100100], B[100100];

#define MAXN 100100
// END CUT HERE
/* scc  : rev  */
int C, N; int scc[MAXN]; ivec graph[MAXN], rev[MAXN], st; int cnt[MAXN];

void visit0(int p) {
	scc[p] = -1;
	for (auto q : graph[p]) if (!scc[q]) visit0(q);
	st.push_back(p);
}
void visit1(int p) {
	scc[p] = C;
	for (auto q : rev[p]) if (!~scc[q]) visit1(q);
}
void scc_go() {
	memset(scc, 0, N * 4); C = 0;
	for (int i = 0; i < N; ++i) if (!scc[i]) visit0(i);
	for (int i = N - 1; i >= 0; --i) if (!~scc[st[i]]) ++C, visit1(st[i]);
}

bool vis[100100];

pair<int, int> visit(int p)
{
	if (vis[p]) return make_pair(0, 0);
	vis[p] = true;
	int ret = 1, flg = 0;
	for (auto x : graph[p]) {
		auto tmp = visit(x);
		ret += tmp.first;
		flg |= tmp.second;
	}
	for (auto x : rev[p]) {
		auto tmp = visit(x);
		ret += tmp.first;
		flg |= tmp.second;
	}

	if (cnt[scc[p]] >= 2) flg = 1;

	return make_pair(ret, flg);
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", A + i, B + i);

		--A[i]; --B[i];

		graph[A[i]].push_back(B[i]);
		rev[B[i]].push_back(A[i]);
	}
	scc_go();

	for (int i = 0; i <= N; ++i) {
		vis[i] = false;
		cnt[i] = 0;
	}

	for (int i = 0; i < N; ++i) {
		++cnt[scc[i]];
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			auto x = visit(i);
			ret += x.first + x.second - 1;
		}
	}

	printf("%d\n", ret);
	return 0;
}