#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;

int n;
int u[MAXN], v[MAXN];
int w[MAXN], p[MAXN];
int d[MAXN];
vector<PII> E[MAXN];

ll tot[MAXN];

bool failed = false;

void DFS1(int u, int pre){
	tot[u] = 0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre)
			continue;

		DFS1(v, u);
		int t = E[u][i].nd;
		if (p[t] < tot[v])
			failed = true;
		else{
			d[t] = min(w[t] - 1ll, p[t] - tot[v]);
			tot[u] += tot[v] + (w[t] - d[t]);
		}
	}
}

ll DFS2(int u, int pre, ll limit){
	ll s = 0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre)
			continue;

		int t = E[u][i].nd;
		if (d[t] <= limit - s)
			s += d[t], d[t] = 0;
		else
			d[t] -= limit - s, s = limit;
		s += DFS2(v, u, min(limit - s, (p[t] - d[t]) - tot[v]));
	}
	return s;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		scanf("%d%d%d%d", u + i, v + i, w + i, p + i);
		E[u[i]].push_back(PII(v[i], i));
		E[v[i]].push_back(PII(u[i], i));
	}
	DFS1(1, 0);
	if (failed){
		puts("-1");
		return 0;
	}
	DFS2(1, 0, 1ll << 60);
	printf("%d\n", n);
	for (int i = 1; i < n; ++i)
		printf("%d %d %d %d\n", u[i], v[i], w[i] - d[i], p[i] - d[i]);
	return 0;
}