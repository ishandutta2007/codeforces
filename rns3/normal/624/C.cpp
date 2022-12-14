#include <bits/stdc++.h>
using namespace std;

#define M 501

int con[M][M], col[M];
vector<int> v[M];
char s[M];
int n, m;

void dfs(int u, int c) {
    col[u] = c;
    for(int i = 0; i < v[u].size(); i ++) {
    	int x = v[u][i];
		if(col[x] == c) {puts("No"); exit(0);}
		if(col[x]) continue;
		dfs(x, 3 - c);
    }
}

int main() {
	///freopen("3.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1;  i <= n; i ++) for(int j = i + 1; j <= n; j ++) con[i][j] = con[j][i] = 1;
    for(int i = 0; i < m; i ++) {
    	int x, y;
		scanf("%d %d", &x, &y);
		con[x][y] = 0;
		con[y][x] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) if(con[i][j]) {
            v[i].push_back(j);
			v[j].push_back(i);
        }
    }
    for(int i = 1; i <= n; i ++) if(v[i].size()) {
    	dfs(i, 1);
		break;
    }
    for(int i = 1; i <= n; i ++) {
    	if(col[i] == 1) s[i] = 'a';
		else if(col[i] == 2) s[i] = 'c';
		else s[i] = 'b';
    }
    for(int i = 1; i <= n; i ++) {
    	for(int j = i + 1; j <= n; j ++) {
    		if(abs(s[i] - s[j]) == 2 && !con[i][j]) {puts("No");exit(0);}
    		if(abs(s[i] - s[j]) != 2 && con[i][j]) {puts("No"); exit(0);}
    	}
    }
    puts("Yes");
    puts(s + 1);
}