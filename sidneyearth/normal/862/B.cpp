#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
struct Edge{
	int u, v, nxt;
}e[2 * maxn];
int head[maxn], e_cnt, f[maxn], a, b;
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
void DFS(int u, int fa){
	f[u] = f[fa]^1;
	if(f[u]) a++;
	else b++;
	for(int id = head[u]; id != -1; id = e[id].nxt)
		if(e[id].v != fa) DFS(e[id].v, u);
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		head[i] = -1;
	e_cnt = 0;
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		Add(u, v);
		Add(v, u);
	}
	DFS(1, 0);
	printf("%I64d\n", (ll)a * b - (n - 1));
	return 0;
}