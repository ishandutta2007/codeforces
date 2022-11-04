#include<bits/stdc++.h>

using namespace std;

#define M 1005

const int inf = 10000000;

int weight[M], a[M][M];
int dis[M], _dis[M], S[M], E[M];

struct edge{
	int v, id;
	edge(int v = 0, int id = 0) : v(v), id(id){}
};

struct Data{
	int num, dist;
	
	Data(int num = 0, int dist = 0) : num(num), dist(dist){
	}
	
	bool operator < (const Data &data) const{
		return dist > data.dist;
	}
};

vector<edge> con[M];
priority_queue<Data> q;

int n;

void dijkstra(int st){
	fill(dis, dis + n + 1, inf);
	
	dis[st] = 0;
	
	while(!q.empty()) q.pop();
	
	q.push(Data(st, 0));
	
	while(!q.empty()){
		Data data = q.top(); q.pop();
		
		for(edge e : con[data.num]) {
			if(dis[e.v] > data.dist + weight[e.id]){
				dis[e.v] = data.dist + weight[e.id];
				q.push(Data(e.v, dis[e.v]));
			}
		}
	}
}

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int m, k, i, j, u, v, w;
	int tot = 0;
	
	cin >> n >> m >> k;
	
	for(i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		
		con[u].push_back(edge(v, i));
		con[v].push_back(edge(u, i));
		
		S[i] = u; E[i] = v;
		weight[i] = w;
	}
	
	
	for(i = 1; i <= k; i ++){
		cin >> u >> v;
		
		dijkstra(u);
		memcpy(_dis, dis, sizeof(_dis));
		
		dijkstra(v);
		
		for(j = 1; j <= m; j ++){
			a[i][j] = max(0, _dis[v] - min(dis[S[j]] + _dis[E[j]], dis[E[j]] + _dis[S[j]]));
		}
		
		tot += _dis[v];
	}
	
	int res = INT_MAX;
	
	for(i = 1; i <= m; i ++){
		int tmp = 0;
		for(j = 1; j <= k; j ++){
			tmp += a[j][i];
		}
		
		res = min(res, tot - tmp);
	}
	
	cout << res << endl;
	
	return 0;
}