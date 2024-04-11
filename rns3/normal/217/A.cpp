#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];
bool con[101][101];
int vis[101];
queue<int> q;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
	for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) {
        if(a[i] == a[j] || b[i] == b[j]) con[i][j] = con[j][i]= 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
        ans ++;
		q.push(i);
		vis[i] = 1;
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int j = 1; j <= n; j ++) if(con[x][j] && !vis[j]) {
				vis[j] = 1;
				q.push(j);
			}
		}
	}
	printf("%d\n", ans - 1);
}