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
vector<int> graph[101010];
int dbl[101010][17], dep[101010];
int lft[101010], rig[101010], oid;

void visit(int p, int rt, int d)
{
	dep[p] = d;
	lft[p] = oid++;
	if (rt == -1) {
		for (int i = 0; i < 17; ++i) dbl[p][i] = -1;
	} else {
		dbl[p][0] = rt;
		for (int i = 1; i < 17; ++i) dbl[p][i] = (dbl[p][i - 1] == -1 ? -1 : dbl[dbl[p][i - 1]][i - 1]);
	}

	for (int q : graph[p]) if (q != rt) visit(q, p, d + 1);

	rig[p] = oid;
}

int lca(int p, int q)
{
	if (dep[p] > dep[q]) swap(p, q);
	for (int i = 16; i >= 0; --i) {
		if (dep[q] - (1 << i) >= dep[p]) q = dbl[q][i];
	}
	if (p == q) return p;

	for (int i = 16; i >= 0; --i) {
		if (dbl[p][i] != dbl[q][i]) {
			p = dbl[p][i];
			q = dbl[q][i];
		}
	}
	return dbl[p][0];
}

vector<int> K;

vector<int> subtree[101010];
int sid;
int real[101010];
bool important[101010];

pair<int, int> dfs(int p)
{
	int reta = 0, retb = 0;
	vector<pair<int, int> > subs;

	for (int q : subtree[p]) {
		auto tmp = dfs(q);
		if (dbl[real[q]][0] != real[p]) {
			tmp.first = min(tmp.first, tmp.second + 1);
		}
		subs.push_back(tmp);
	}

	if (important[real[p]]) {
		for (auto a : subs) {
			retb += a.first;
			if (retb > N) retb = N + 1;
		}
		reta = N + 1;
	} else {
		i64 reta2 = 0;
		int max_gap = 0;
		for (auto a : subs) {
			reta2 += a.first;
			max_gap = max(max_gap, a.first - a.second);
		}

		if (reta2 > N) reta = N + 1;
		else reta = reta2;

		i64 retb2 = reta2 - max_gap;
		if (retb2 > N) retb = N + 1;
		else retb = retb2;

		int reta3 = 1;
		for (auto a : subs) {
			reta3 += a.second;
			if (reta3 > N) break;
		}

		reta = min(reta, reta3);
		retb = min(retb, reta);
	}

//	printf("%d: %d %d\n", p, reta, retb);
	return{ reta, retb };
}

int solve()
{
	vector<pair<int, int> > imp;
	for (int i : K) imp.push_back({ lft[i], i });
	for (int v : K) important[v] = true;
	sort(imp.begin(), imp.end());

	vector<int> cand;
	for (int i = 0; i < imp.size(); ++i) cand.push_back(imp[i].second);
	for (int i = 1; i < imp.size(); ++i) cand.push_back(lca(imp[i - 1].second, imp[i].second));
	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());

	vector<pair<int, pair<int, int> > > eve;
	for (int v : cand) {
		eve.push_back({ rig[v],{ -lft[v], v } });
	}
	sort(eve.begin(), eve.end());

	sid = 0;
	stack<int> S;

	for (auto e : eve) {
		int p = e.second.second;
		int myid = sid++;
		real[myid] = p;
	//	printf("%d %d\n", p, lft[p]);
		while (S.size() > 0 && lft[real[S.top()]] >= lft[p]) {
			subtree[myid].push_back(S.top());
			S.pop();
		}
		S.push(myid);
	}

	int top = S.top();
	int ret = dfs(top).second;
	if (ret > N) ret = -1;

/*	printf("%d, %d\n", sid, top);
	for (int i = 0; i < sid; ++i) {
		printf("%d[%d]: ", i, real[i]);
		for (int j : subtree[i]) printf("%d ", j);
		puts("");
	} */
	for (int i = 0; i < sid; ++i) subtree[i].clear();
	for (int v : K) important[v] = false;

	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	oid = -1;
	visit(0, -1, 0);
	int Q;
	scanf("%d", &Q);
	for (; Q--; ) {
		int c, x;
		scanf("%d", &c);
		K.clear();
		for (; c--;) {
			scanf("%d", &x);
			--x;
			K.push_back(x);
		}

		printf("%d\n", solve());
	}

	return 0;
}