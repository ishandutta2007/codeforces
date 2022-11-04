#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3e5 + 2;

int n, m, c, x, col[N][2], fa[N << 1], sz[N << 1][2], ans;
char s[N];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	ans -= min(sz[x][0], sz[x][1]) + min(sz[y][0], sz[y][1]);
	fa[y] = x;
	sz[x][0] += sz[y][0], sz[x][1] += sz[y][1];
	ans += min(sz[x][0], sz[x][1]);
}

int main(){
	scanf("%d%d%s", &n, &m, s + 1);
	++m;
	for(int i = 1; i < m; i++){
		scanf("%d", &c);
		while(c--){
			scanf("%d", &x);
			col[x][(bool)col[x][0]] = i;
		}
	}
	for(int i = 0; i < (m << 1); i++){
		fa[i] = i;
		sz[i][i >= m] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(s[i] - '0'){
			merge(col[i][0], col[i][1]);
			merge(col[i][0] + m, col[i][1] + m);
		}else{
			merge(col[i][0], col[i][1] + m);
			merge(col[i][1], col[i][0] + m);
		}
		int x = find(0);
		if(sz[x][0] < sz[x][1]) printf("%d\n", (ans >> 1) - sz[x][0] + sz[x][1]);
		else printf("%d\n", ans >> 1);
	}
	return 0;
}