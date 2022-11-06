#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pair;
const int maxn = (int)2e5 + 1;
int n, qtot, dsu[maxn], msk[maxn];
map<int, Pair> tim[maxn];
Pair que[maxn];
struct Edge {
	int L, R, u, v, w;
} ;
Pair dsu_find(int u) {
	int ret = 0;
	for( ; dsu[u] >= 0; ret ^= msk[u], u = dsu[u]);
	return (Pair){u, ret};
}
int dsu_merge(int u, int v, int w, stack<Pair> &his) {
	Pair tmp = dsu_find(u);
	u = tmp.first;
	w ^= tmp.second;
	tmp = dsu_find(v);
	v = tmp.first;
	w ^= tmp.second;
	if(u == v)
		return w;
	if(dsu[u] > dsu[v])
		swap(u, v);
	his.push((Pair){u, dsu[u]});
	his.push((Pair){v, dsu[v]});
	if(dsu[u] == dsu[v])
		--dsu[u];
	dsu[v] = u;
	msk[v] = w;
	return 0;
}
void solve(int L, int R, vector<Edge> &edges, vector<int> base) {
	int M = (L + R) >> 1;
	stack<Pair> his;
	vector<Edge> lft, rht;
	// printf("solve [%d, %d]\n", L, R);
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it)
		if(it -> L <= L && R <= it -> R) {
			// printf("merge (%d, %d, %d)\n", it -> u, it -> v, it -> w);
			base.push_back(dsu_merge(it -> u, it -> v, it -> w, his));
		} else {
			if(it -> L <= M)
				lft.push_back(*it);
			if(M < it -> R)
				rht.push_back(*it);
		}
	vector<Edge>().swap(edges);
	int rk = 0;
	for(int sz = (int)base.size(); rk < sz; ++rk) {
		for(int j = rk + 1; j < sz; ++j)
			if(base[rk] < base[j])
				swap(base[rk], base[j]);
		if(!base[rk])
			break;
		for(int j = rk + 1; j < sz; ++j)
			if((base[j] ^ base[rk]) < base[j])
				base[j] ^= base[rk];
	}
	base.resize(rk);
	// printf("rank: %d\n", rk);
	// for(int i = 0; i < rk; ++i, putchar('\n'))
		// for(int j = 0; j < 30; ++j)
			// putchar('0' + ((base[i] >> j) & 1));
	if(!lft.size()) {
		for(int i = L; i <= M; ++i) {
			int tmp = dsu_find(que[i].first).second ^ dsu_find(que[i].second).second;
			for(int j = 0; j < rk; ++j)
				if((tmp ^ base[j]) < tmp)
					tmp ^= base[j];
			que[i].first = tmp;
			// printf("ans %d: %d\n", i, tmp);
		}
	} else {
		solve(L, M, lft, base);
	}
	if(!rht.size()) {
		for(int i = M + 1; i <= R; ++i) {
			int tmp = dsu_find(que[i].first).second ^ dsu_find(que[i].second).second;
			for(int j = 0; j < rk; ++j)
				if((tmp ^ base[j]) < tmp)
					tmp ^= base[j];
			que[i].first = tmp;
			// printf("ans %d: %d\n", i, tmp);
		}
	} else {
		solve(M + 1, R, rht, base);
	}
	while(!his.empty()) {
		Pair tmp = his.top();
		his.pop();
		dsu[tmp.first] = tmp.second;
		msk[tmp.first] = 0;
		tmp = his.top();
		his.pop();
		dsu[tmp.first] = tmp.second;
	}
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		tim[u][v] = (Pair){qtot + 1, w};
	}
	vector<Edge> edges;
	scanf("%d", &m);
	while(m--) {
		int typ, u, v, w;
		scanf("%d%d%d", &typ, &u, &v);
		if(typ == 1) {
			scanf("%d", &w);
			tim[u][v] = (Pair){qtot + 1, w};
		} else if(typ == 2) {
			Pair tmp = tim[u][v];
			if(tmp.first <= qtot) {
				// printf("[%d, %d] add (%d, %d, %d)\n", tmp.first, qtot, u, v, tmp.second);
				edges.push_back((Edge){tmp.first, qtot, u, v, tmp.second});
			}
			tim[u].erase(v);
		} else {
			que[++qtot] = (Pair){u, v};
		}
	}
	for(int u = 1; u <= n; ++u)
		for(map<int, Pair>::iterator it = tim[u].begin(); it != tim[u].end(); ++it) {
			int v = it -> first;
			Pair tmp = it -> second;
			if(tmp.first <= qtot) {
				// printf("[%d, %d] add (%d, %d, %d)\n", tmp.first, qtot, u, v, tmp.second);
				edges.push_back((Edge){tmp.first, qtot, u, v, tmp.second});
			}
		}
	memset(dsu + 1, -1, n * sizeof(int));
	solve(1, qtot, edges, vector<int>());
	for(int i = 1; i <= qtot; ++i)
		printf("%d\n", que[i].first);
	return 0;
}