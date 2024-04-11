#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;
queue<Pair> q;
const int maxn = 1000010;
struct Edge{
	int u, v, nxt;
}e[maxn];
int head[2][maxn], e_cnt, f[maxn][2], done[maxn];
void Add(int t, int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[t][u];
	head[t][u] = id;
}
bool DFS(int u){
	if(done[u] == 1) return true;
	else if(done[u] == 2) return false;
	else{
		done[u] = 1;
		for(int id = head[1][u]; id != -1; id = e[id].nxt)
			if(DFS(e[id].v)) return true;
		done[u] = 2;
		return false;
	}
};
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n + 1; i++)
		head[0][i] = head[1][i] = -1;
	for(int i = 1; i <= n; i++){
		int c; scanf("%d", &c);
		for(int j = 1; j <= c; j++){
			int u; scanf("%d", &u);
			Add(0, u, i);
			Add(1, i, u);
		}
		if(c == 0) Add(0, n + 1, i);
	}
	int s; scanf("%d", &s);
	q.push(Pair(n + 1, 0));
	f[n + 1][0] = true;
	while(!q.empty()){
		int u = q.front().first;
		int t = q.front().second;
		q.pop();
		for(int id = head[0][u]; id != -1; id = e[id].nxt)
			if(!f[e[id].v][t^1]){
				f[e[id].v][t^1] = u;
				q.push(Pair(e[id].v, t^1));
			}
	}
	if(f[s][0]){
		int u = s, t = 0;
		printf("Win\n");
		while(u != n + 1){
			printf("%d ", u);
			u = f[u][t];
			t ^= 1;
		}
		printf("\n");
	}
	else if(DFS(s))
		printf("Draw\n");
	else 
		printf("Lose\n");
	return 0;
}