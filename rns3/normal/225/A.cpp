#include <bits/stdc++.h>
using namespace std;

int vis[1001][1001];
int a[101], b[101];

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &b[i]);
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	for(int i = 1; i <= n; i++) {
        vis[i][a[i]] = 1;
		vis[i][b[i]] = 1;
		vis[i][7-a[i]] = 1;
		vis[i][7-b[i]] = 1;
	}
	for(int i = 1;  i <= n; i++) {
		for(int j = i + 1; j <= n ; j ++) {
			for(int k = 1; k <= 6; k ++) if(vis[i][k] != vis[j][k]) return puts("NO");
		}
	}
	puts("YES");
}