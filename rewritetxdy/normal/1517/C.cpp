#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,a[505],c[505][505],vis[505][505];

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++){
		scanf("%d",&c[i][i]);
		if(c[i][i] == 1) vis[i][i] = 1;
	}
	for(int i=1;i <= n-1;i++) for(int y=1;y <= n-i;y++){
		int x = y+i;
		if(vis[x-1][y])
			c[x][y] = c[x][y+1] , vis[x][y+1] = 1;
		else c[x][y] = c[x-1][y] , vis[x-1][y] = 1;
		if(c[x][y] == i+1) vis[x][y] = 1; 
	}
	for(int i=1;i <= n;i++) for(int j=1;j <= i;j++) printf("%d%c",c[i][j],j == i ? '\n' : ' ');
	return 0;
}