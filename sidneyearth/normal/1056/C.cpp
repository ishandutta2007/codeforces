#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;
const int maxn = 20100;
int vis[maxn], p[maxn], par[maxn];
priority_queue<Pair> q1, q2;
void Print(int x){
	printf("%d\n", x);
	vis[x] = true;
	fflush(stdout);
}
void MyTurn(int x){
	if(x != -1){
		if(par[x] && !vis[par[x]]) Print(par[x]);
		else MyTurn(-1);
	}
	else{
		while(!q1.empty()){
			int u = q1.top().second; q1.pop();
			if(!vis[u]){
				Print(u);
				return;
			}
		}
		while(!q2.empty()){
			int u = q2.top().second; q2.pop();
			if(!vis[u]){
				Print(u);
				return;
			}
		}
	}
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= 2 * n; i++){
		scanf("%d", &p[i]);
		q2.push(Pair(p[i], i));
	}
	for(int i = 1; i <= m; i++){
		int u, v; scanf("%d%d", &u, &v);
		par[u] = v; par[v] = u;
		if(p[u] > p[v]) q1.push(Pair(p[u] - p[v], u));
		else q1.push(Pair(p[v] - p[u], v));
	}
	int t; scanf("%d", &t);
	if(t == 1)
		for(int k = 1; k <= n; k++){
			MyTurn(-1);
			int x; scanf("%d", &x);
			vis[x] = true;
		}
	else
		for(int k = 1; k <= n; k++){
			int x; scanf("%d", &x);
			vis[x] = true;
			MyTurn(x);
		}
	return 0;
}