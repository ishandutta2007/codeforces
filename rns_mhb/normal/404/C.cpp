#include <stdio.h>
#include <algorithm>
#include <vector>
#define N 100100

using namespace std;

int d[N], id[N];
vector <int> v[N], que;
bool vis[N];

bool cmp(int a, int b) {
	return d[a]<d[b];
}

void dfs(int u) {
	vis[u]=1;
	int i, w;
	for (i=0; i<v[u].size(); i++) {
		w=v[u][i];
		if (vis[w]) continue;
		printf("%d %d\n", u, w);
		dfs(w);
	}
}

int main() {
	int n, i, dis, j, k, cnt, p, tmp, hi;
//	freopen ("in.txt", "r", stdin);
	scanf("%d %d", &n, &hi);
	for (i=1; i<=n; i++) scanf("%d", d+i), id[i]=i;
	sort(id+1, id+n+1, cmp);
	if (d[id[1]] || d[id[1]]==d[id[2]]) {
		puts("-1");
		return 0;
	}
	que.push_back(id[1]);
	for (i=2; i<=n; ) {
		for (j=i+1; j<=n; j++) if (d[id[j]]!=d[id[i]]) break;
		dis=d[que[0]];
		if (d[id[i]]>dis+1) break;
		cnt=que.size(), p=0;
		for (k=i; k<j; k++) {
			tmp=que[p];
			if (v[tmp].size()==hi) p++;
			if (p==cnt) break;
			tmp=que[p];
			v[tmp].push_back(id[k]);
			v[id[k]].push_back(tmp);
		}
		if (k<j) break;
		que.clear();
		for (k=i; k<j; k++) que.push_back(id[k]);
		i=j;
	}
	if (i<=n) {
		puts("-1");
		return 0;
	}
	printf("%d\n", n-1);
	dfs(id[1]);
}