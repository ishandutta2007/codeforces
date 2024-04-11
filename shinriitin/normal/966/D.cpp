#include <bits/stdc++.h>

#define inf (0x3f3f3f3f)

const int max_N = (int)3e5 + 21;

const int log_N = 18;

int n, m, dis[max_N], pre[max_N], vis[max_N], _vis[max_N];

std::vector<int> vec[max_N];

int q[max_N], t;

void bfs(){
	for(int h=1;h<=t;++h){
		int x = q[h];
		for(auto&y:vec[x])
			if(dis[y] == inf){
				dis[y] = dis[x] + 1;
				pre[y] = x;
				q[++t] = y;
			}
	}
}

bool check4(){
	for(int i=1;i<=n;++i) if(dis[i] == 2){
		printf("4\n1 %d %d 1 %d\n", pre[i], i, n);
		return true;
	}
	return false;
}

bool check5(){
	for(int i=1;i<=n;++i) dis[i] = inf;
	dis[1] = 0;
	for(auto&x:vec[1]){
		if(dis[x] < inf) continue;
		dis[x] = 0, q[t=1] = x, bfs();
		for(int i=1;i<=t;++i) if(dis[q[i]] == 2){
			printf("5\n1 %d %d %d %d %d\n", x, pre[q[i]], q[i], x, n);
			return true;
		}
		for(auto&y:vec[x]) _vis[y] = x;
		for(auto&y:vec[x]){
			int cnt = 0;
			for(auto&z:vec[y]){
				vis[z] = y;
				cnt += _vis[z] == x;
			}
			if(cnt+1 == (int)vec[x].size()) continue;
			for(auto&z:vec[x]) if(z!=y && vis[z] != y){
				printf("5\n1 %d %d %d %d %d\n", y, x, z, y, n);
				return true;
			}
		}
	}
	return false;
}

void display(int x){
	if(!x) return;
	display(pre[x]);
	printf("%d ", x);
}

int main(){
	scanf("%d%d", &n, &m);
	while(m --){
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;++i) dis[i] = inf;
	dis[1] = 0, q[t=1] = 1, bfs();
	if(dis[n]<5){
		printf("%d\n", dis[n]);
		display(n), puts("");
	}
	else if(!check4() && !check5()){
		puts("-1");
	}
	return 0;
}