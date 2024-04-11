#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIP;

const int MAXN = 1E6 + 10;

vector<vector<int> > a;
vector<vector<int> > b;

PII f[MAXN];

vector<int> E[MAXN];
vector<int> lst[MAXN];
int deg[MAXN];

int fa[MAXN], val[MAXN];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void merge(int u, int v){
	u = find(u), v = find(v);
	fa[u] = v;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i){
		a.push_back(vector<int>(m));
		b.push_back(vector<int>(m));
		for (int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}

	for (int i = n * m - 1; i >= 0; --i)
		fa[i] = i;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			f[j] = PII(a[i][j], j);
		sort(f, f + m);
		int tn = i * m;
		for (int j = 0; j < m - 1; ++j){
			if (f[j].st < f[j + 1].st)
				E[tn + f[j].nd].push_back(tn + f[j + 1].nd);
			else
				merge(tn + f[j].nd, tn + f[j + 1].nd);
		}
	}
	for (int j = 0; j < m; ++j){
		for (int i = 0; i < n; ++i)
			f[i] = PII(a[i][j], i);
		sort(f, f + n);
		for (int i = 0; i < n - 1; ++i)
			if (f[i].st < f[i + 1].st)
				E[f[i].nd * m + j].push_back(f[i + 1].nd * m + j);
			else
				merge(f[i].nd * m + j, f[i + 1].nd * m + j);
	}

	queue<int> Q;
	for (int i = n * m - 1; i >= 0; --i)
		for (int j = 0; j < E[i].size(); ++j)
			++deg[E[i][j] = find(E[i][j])];
	for (int i = n * m - 1; i >= 0; --i){
		if (fa[i] == i && deg[i] == 0){
			Q.push(i);
			val[i] = 1;
		}
		lst[find(i)].push_back(i);
	}

	while (!Q.empty()){
		int uu = Q.front();
		Q.pop();

		for (int ii = 0; ii < lst[uu].size(); ++ii){
			int u = lst[uu][ii];
			val[u] = val[uu];
			for (int v, i = 0; i < E[u].size(); ++i){
				v = E[u][i];
				val[v] = max(val[v], val[uu] + 1);
				if (--deg[v] == 0)
					Q.push(v);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			printf("%d%c", val[i * m + j], "\n "[j < m - 1]);
	return 0;
}