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

int n;
vector<int> E[MAXN];
int dep[MAXN], p[MAXN];
set<int> lst;

void DFS(int u, int pre){
	dep[u] = dep[pre] + 1;
	p[u] = pre;
	for (int v: E[u]){
		if (v == pre)
			continue;
		DFS(v, u);
	}
}

void DFS2(int u, int pre){
	dep[u] = dep[pre] + 1;
	bool leaf = true;
	for (int v: E[u]){
		if (v == pre)
			continue;
		leaf = false;
		DFS2(v, u);
	}
	if (leaf)
		lst.insert(dep[u]);
}

int main(){
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	int root = max_element(dep + 1, dep + n + 1) - dep;
	DFS(root, 0);
	root = max_element(dep + 1, dep + n + 1) - dep;
	for (int t = dep[root] >> 1; t; --t)
		root = p[root];

	bool flag = true;
	set<int> slst;
	dep[root] = 0;
	for (int v: E[root]){
		lst.clear();
		DFS2(v, root);
		flag &= lst.size() == 1;
		slst.insert(*lst.begin());
	}
	if (slst.size() > 2 || !flag)
		puts("-1");
	else{
		int len = *slst.begin() + *slst.rbegin();
		printf("%d\n", len >> __builtin_ctz(len));
	}
	return 0;
}