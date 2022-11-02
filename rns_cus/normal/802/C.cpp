#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 200020

const LL INF = 1e9;

int nxt[N], cost[N], cap[N], to[N], head[N], cnt;

void init(){
	memset(head, -1, sizeof head);
}

void add_Edge(int S, int T, int c, int w){
	nxt[cnt] = head[S], to[cnt] = T, cap[cnt] = c, cost[cnt] = w, head[S] = cnt ++;
	nxt[cnt] = head[T], to[cnt] = S, cap[cnt] = 0, cost[cnt] = -w, head[T] = cnt ++;
}

int prv[N], vis[N];
LL dist[N];

LL SPFA(int S, int T, int vet){
	queue <int> Q;
	fill(dist, dist + vet, INF);
	fill(prv, prv + vet, -1);
	dist[S] = 0, Q.push(S), vis[S] = true;
	while(!Q.empty() ){
		int x = Q.front();
		Q.pop(), vis[x] = false;
		for(int id = head[x]; ~id; id = nxt[id]) if( cap[id] ){
			int y = to[id];
			if(dist[y] > dist[x] + cost[id]){
				dist[y] = dist[x] + cost[id];
				prv[y] = id;
				if(!vis[y]) Q.push(y), vis[y] = true;
			}
		}
	}

	if(!~prv[T]){ return INF; }

	int cur = T;
	while( cur != S ) {
		cur = prv[cur];
		cap[cur] --;
		cap[cur^1] ++;
		cur = to[cur^1];
	}
	return dist[T];
}

int a[N], c[N], n, m;

int main(){
	///freopen("in.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", c + i);

	init();

	LL ans = 0;
	int S = n + 1, T = 2 * n + 2;
	for(int i = 1; i <= n; i ++){
		ans += c[a[i]];
		add_Edge(S, i, 1, 0);
		add_Edge(i, S + i, 1, -INF);
		for(int j = i + 1; j <= n; j ++){
			if(a[i] == a[j]) add_Edge(i + S, j, 1, -c[a[j]]);
			else add_Edge(i + S, j, 1, 0);
		}
		add_Edge(i + S, T, 1, 0);
	}

	for(int step = 1; step <= m; step ++){
		LL tmp = SPFA(S, T, T + 1);
		if(tmp >= 0) break;
		ans += tmp;
	}
	cout << ans + INF * n << endl;
}