#include <bits/stdc++.h>

using namespace std;

#define Pa pair <int , int>
#define N 5100

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

int head[N] , cnt , f[N][N] , n , m , T , d[N] , pre[N][N] , ans;

struct edge {
	int nxt , to , w;
}e[N << 2];

void insert(int u , int v , int w) {
	e[++ cnt].nxt = head[u] , e[head[u] = cnt].to = v , e[cnt].w = w , d[v] ++;
}

vector <int> G;

int main() {
	n = read() , m = read() , T = read();
	for (int i = 1 ; i <= m ; i ++) {
		int u = read() , v = read() , w = read();
		insert(u , v , w);
	} 
	memset(f , 0x3f , sizeof f);
	f[1][1] = 0;
	queue < Pa > Q;
	Q.push(make_pair(1 , 1));
	while(!Q.empty()) {
		Pa now = Q.front();Q.pop();
		for (int i = head[now.first] ; i ; i = e[i].nxt) {
			int v = e[i].to;
			if (f[v][now.second + 1] > f[now.first][now.second] + e[i].w) {
				f[v][now.second + 1] = f[now.first][now.second] + e[i].w;
				pre[v][now.second + 1] = now.first;
				Q.push(make_pair(v , now.second + 1));
			}		
		}
	}
	for (int i = 1 ; i <= n ; i ++) if (f[n][i] <= T) ans = i;
	printf("%d\n" , ans);
	int u = n;
	
	int t = ans;
	while (u != 1) {
		G.push_back(u);
		u = pre[u][t --];
	}
	G.push_back(1);
	for (int i = G.size() - 1 ; i >= 0 ; i -- ) printf("%d " , G[i]);
	return 0;
}