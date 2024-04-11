#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 200020

int to[N], head[N], nxt[N], cost[N], cap[N], cnt;

void init(){ memset(head, -1, sizeof head); }

void add_Edge(int S, int T, int c, int w){
	nxt[cnt] = head[S], cap[cnt] = c, cost[cnt] = w, to[cnt] = T, head[S] = cnt ++;
	nxt[cnt] = head[T], cap[cnt] = 0, cost[cnt] = -w, to[cnt] = S, head[T] = cnt ++;
}

const LL INF = 1e14;

LL dist[N];
int prv[N];

LL SPFA(int S, int T, int vet){
	queue <pair <int, int> > Q;
	fill(prv, prv + vet, -1);
	fill(dist, dist + vet, INF);
	Q.push(make_pair(S, 0)); dist[S] = 0;
	for(int i = 0; i < vet; i ++){
		int sz = Q.size(); if(!sz) break;
		for(int j = 0; j < sz; j ++) {
			int x = Q.front().first, val = Q.front().second; Q.pop();
			if(val != dist[x]) continue;
			for(int id = head[x]; ~id; id = nxt[id]) if( cap[id] ){
				int y = to[id];
				if(dist[y] > dist[x] + cost[id]){
					dist[y] = dist[x] + cost[id];
					prv[y] = id;
					Q.push( make_pair(y, dist[y]) );
				}
			}
		}
	}
	while(!Q.empty()) Q.pop();
	if(!~prv[T]) { return INF; }

	for(int cur = T; cur != S; cur = to[cur^1]){
		cur = prv[cur];
		cap[cur] --;
		cap[cur ^ 1] ++;
	}
	return dist[T];
}

int a[N], b[N], n, k;

int main(){
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);

	int S = 0, T = 2 * n + 1;
	init();
	for(int i = 1; i <= n; i ++){
		add_Edge(S, i, 1, a[i]);
		add_Edge(i + n, T, 1, b[i]);
		add_Edge(i, i + n, n, 0);
		if(i < n) add_Edge(i + n, i + n + 1, n - i, 0);
	}
	LL ans = 0;
	for(int i = 1; i <= k; i ++) ans += SPFA(S, T, T + 1);
	cout << ans << endl;
}