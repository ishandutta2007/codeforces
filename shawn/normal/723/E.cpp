#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

vector<pair<int , int > > G;

struct edge{
	int nxt , to , w;
}e[N << 4];

bool vis[N];

int head[N] , d[N] , cnt = 1 , m , n , ans;

void insert(int u , int v , int w) {
	e[++ cnt].nxt = head[u] , e[head[u] = cnt].to = v , e[cnt].w = w;
}

void dfs(int u) {
	if (!vis[u]) vis[u] = 1 , cnt ++;
	for (int i = head[u] ; i ; i = e[i].nxt) {
		int v = e[i].to;
		if (e[i].w == 0) continue;
		G.push_back(make_pair(u , v));
		d[u] -- , d[v] --;
		e[i].w = e[i ^ 1].w = 0;
		dfs(v);
		break;
	}
}

int main() {
	for (int t = read() ; t ; t --) {
		n = read() , m = read();
		memset(d , 0 , sizeof d);
		memset(vis , 0 , sizeof vis);
		memset(head , 0 , sizeof head);
		cnt = 1;
		ans = 0 ;
		G.clear();
		for (int i = 1 ; i <= m ; i ++) {
			int x = read() , y = read();
			d[x] ++ , d[y] ++;
			insert(x , y , 1) , insert(y , x , 1);
		}
		for (int i = 1 ; i <= n ; i ++) 
			if (d[i] & 1) cnt = 0 , dfs(i) , ans += cnt - 2;
		for (int i = 1 ; i <= n ; i ++) {
			if (d[i]) cnt = 0 , dfs(i) , ans += cnt;
			else if (d[i] == 0 && vis[i] == 0) ans ++;
		}
		printf("%d\n" , ans);
		for (int i = 0 ; i < G.size() ; i ++) printf("%d %d\n", G[i].first , G[i].second);
	}
	return 0;
}