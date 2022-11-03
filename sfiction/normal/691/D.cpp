#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

const int MAXN = 1E6 + 10;

int a[MAXN];
int fa[MAXN];
vector<int> b[MAXN];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		fa[i] = i;
	}
	for (int u, v, j = 0; j < m; ++j){
		scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if (u != v)
			fa[v] = u;
	}
	for (int i = 1; i <= n; ++i)
		b[find(i)].push_back(i);
	for (int i = 1; i <= n; ++i){
		if (b[i].size() == 0)
			continue;
		vector<int> c(b[i].size());
		for (int j = 0; j < b[i].size(); ++j)
			c[j] = a[b[i][j]];
		sort(c.begin(), c.end(), greater<int>());
		for (int j = 0; j < b[i].size(); ++j)
			a[b[i][j]] = c[j];
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], "\n "[i < n]);
	return 0;
}