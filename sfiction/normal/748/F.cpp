#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n, k;
int mark[MAXN], size[MAXN];
vector<int> E[MAXN];

int root;

void DFS(int u, int pre){
	bool flag = true;
	for (int v: E[u]){
		if (v == pre)
			continue;
		DFS(v, u);
		size[u] += size[v];
		flag &= size[v] <= k;
	}
	if (flag &= 2 * k - size[u] <= k)
		root = u;
}

vector<vector<int>> lst;

void DFS2(int u, int pre){
	if (mark[u])
		lst.back().push_back(u);
	for (int v: E[u]){
		if (v == pre)
			continue;
		DFS2(v, u);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int x, i = k << 1; i > 0; --i)
		scanf("%d", &x), size[x] = mark[x] = 1;
	DFS(1, 0);
	for (int v: E[root])
		lst.emplace_back(), DFS2(v, root);
	if (mark[root])
		lst.emplace_back(1, root);

	printf("%d\n%d\n", 1, root);
	auto func = [](int l, int r){return lst[l].size() < lst[r].size();};
	priority_queue<int, vector<int>, decltype(func)> Q(func);
	for (int i = 0; i < lst.size(); ++i)
		if (lst[i].size())
			Q.push(i);

	while (!Q.empty()){
		int u = Q.top();
		Q.pop();
		int v = Q.top();
		Q.pop();
		printf("%d %d %d\n", lst[u].back(), lst[v].back(), root);
		lst[u].pop_back(), lst[v].pop_back();
		if (lst[u].size())
			Q.push(u);
		if (lst[v].size())
			Q.push(v);
	}
	return 0;
}