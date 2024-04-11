#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
int c[MAXN];
vector<int> E[MAXN];

map<int, int> *lst[MAXN];
int cnt[MAXN];
ll sum[MAXN];

void insert(int u, pair<int, int> p){
	(*lst[u])[p.st] += p.nd;
	if ((*lst[u])[p.st] > cnt[u])
		cnt[u] = (*lst[u])[p.st], sum[u] = p.st;
	else if ((*lst[u])[p.st] == cnt[u])
		sum[u] += p.st;
}

void DFS(int u, int pre){
	int w = 0;
	for (int v: E[u])
		if (v != pre){
			DFS(v, u);
			if (!w || lst[w]->size() < lst[v]->size())
				w = v;
		}
	if (w){
		lst[u] = lst[w];
		cnt[u] = cnt[w];
		sum[u] = sum[w];
		for (auto v: E[u])
			if (v != pre && v != w){
				for (auto p: *lst[v])
					insert(u, p);
				delete lst[v];
			}
	}
	else
		lst[u] = new map<int, int>;
	insert(u, make_pair(c[u], 1));
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%I64d%c", sum[i], "\n "[i < n]);
	return 0;
}