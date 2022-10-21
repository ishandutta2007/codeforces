#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1000000000;

typedef pair<int, int> P;

queue<P> que;
int n,m;
int s1,t1,l1,s2,t2,l2;
int dis[3005][3005];
vector<int> G[3005];
bool used[3005];

void set_bfs(int k){
	fill(used+1, used+n+1, false);
	dis[k][k] = 0;
	used[k] = true;
	//while(que.size()) que.pop();
	que.push(P(k,0));
	while(que.size()){
		P p = que.front();
		que.pop();
		for(int i = 0; i < G[p.first].size(); i++){
			int pn = G[p.first][i];
			if(!used[pn]){
				used[pn] = true;
				que.push(P(pn, p.second+1));
				dis[k][pn] = p.second+1;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	int a,b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d%d%d", &s1, &t1, &l1);
	scanf("%d%d%d", &s2, &t2, &l2);
	//set_bfs(2);
	for(int i = 1; i <= n; i++) set_bfs(i);
	int res = INF;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1
				&& dis[s2][i] + dis[i][j] + dis[j][t2] <= l2){
						res = min(res, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[s2][i] + dis[j][t2]);
				}
			if(dis[s1][i] + dis[i][j] + dis[j][t1] <= l1
			    &&  dis[s2][j] + dis[i][j] + dis[i][t2] <= l2){
			    	res = min(res, dis[s1][i] + dis[i][j] + dis[j][t1] + dis[t2][i] + dis[j][s2]);
				}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			printf("%d ", dis[i][j]);
//		}
//		cout << endl;
//	}
    //cout << dis[4][6]<< endl;
	if(dis[s1][t1] <= l1 && dis[s2][t2] <= l2) res = min(res, dis[s1][t1] + dis[s2][t2]);
	if(res == INF) cout << "-1";
	else cout << m - res;
}