#include <cstdio>
#include <bitset>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1 << 10 | 32, MAXQ = 1E5 + 10;

int n, m, q;
vector<pair<int, PII> > E[MAXQ];

bitset<MAXN> a[MAXN], mask;
int tot;

int ans[MAXQ];

void DFS(int u){
	ans[u] = tot;
	for (int i = 0; i < E[u].size(); ++i){
		int v = E[u][i].st;
		PII x = E[u][i].nd;

		if (x.st < 0)
			DFS(v);
		else if (x.nd > 0){
			int t = a[x.st][x.nd];
			a[x.st][x.nd] = 1;
			tot += !t;
			DFS(v);
			tot -= !t;
			a[x.st][x.nd] = t;
		}
		else if (x.nd < 0){
			int t = a[x.st][-x.nd];
			a[x.st][-x.nd] = 0;
			tot -= t;
			DFS(v);
			tot += t;
			a[x.st][-x.nd] = t;
		}
		else{
			int t = a[x.st].count();
			a[x.st] ^= mask;
			tot += m - t - t;
			DFS(v);
			tot -= m - t - t;
			a[x.st] ^= mask;
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i)
		mask.set(i);
	for (int type, u, v, i = 1; i <= q; ++i){
		scanf("%d%d", &type, &u);
		if (type == 1){
			scanf("%d", &v);
			E[i - 1].push_back(make_pair(i, PII(u, v)));
		}
		else if (type == 2){
			scanf("%d", &v);
			E[i - 1].push_back(make_pair(i, PII(u, -v)));
		}
		else if (type == 3)
			E[i - 1].push_back(make_pair(i, PII(u, 0)));
		else if (type == 4)
			E[u].push_back(make_pair(i, PII(-1, 0)));
	}
	DFS(0);
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}