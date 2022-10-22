#include<bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;

int n, m;
int tmp[maxn];
int dis[maxn][maxn];
vector<int> way[maxn];
int act[maxn];

int get_cen() {
	int sz = 0;
	for(int u=1;u<=n;u++) sz += act[u];
	int best = -1, cen = 0;
	for(int u=1;u<=n;u++) {
		if(!act[u]) continue;
		// printf("\tconsider %d: ",u);
		int mx = 0;
		for(auto v : way[u]) {
			if(!act[v]) continue;
			int cnt = 0;
			for(int w=1;w<=n;w++) {
				if(!act[w]) continue;
				if(dis[w][v] < dis[w][u]) cnt++;
			}
			mx = max(mx, cnt);
		}
		// printf("mx = %d\n",mx);
		if(best == -1 || best > mx) {
			best = mx;
			cen = u;
		}
	}
	return cen;
}

int ask(int x) {
	printf("%d\n",x); fflush(stdout);
	char res[10];
	scanf(" %s",res);
	if(res[0] == 'F') return 0;
	else {
		int y; scanf("%d",&y);
		return y;
	}
}

void solve(int tnum) {
	for(int u=1;u<=n;u++) act[u] = 1;
	while(1) {
		int u = get_cen();
		int v = ask(u);
		if(v == 0) break;
		// printf("\tu = %d v = %d\n",u,v);
		for(int w=1;w<=n;w++) {
			if(!act[w]) continue;
			// printf("\t\tw = %d: u %d and v %d\n",w,dis[w][u],dis[w][v]);
			if(dis[w][v] >= dis[w][u]) act[w] = 0;
		}
	}
}

void edge(int u, int v) {
	dis[u][v] = dis[v][u] = 1;
	way[u].push_back(v);
	way[v].push_back(u);
}

int main() {
	int k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = (i == j ? 0 : n);
	for(int i=1;i<=k;i++) {
		int len; scanf("%d",&len); m += len;
		for(int j=1;j<=len;j++) scanf("%d",&tmp[j]);
		for(int j=1;j<len;j++) edge(tmp[j], tmp[j+1]);
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) solve(i);
}