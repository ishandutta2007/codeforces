#include<bits/stdc++.h>
using namespace std;

int a[40], b[40], c[40];

const int N = 33;

typedef long long LL;

bool vis[300][300];

LL x;

int main(){
	cin >> x;
	int cnt = 3;
	for(int i = 0; i <= N; i ++){
		a[i] = cnt ++;
		b[i] = cnt ++;
		c[i] = cnt ++;
	}

	vis[1][a[0]] = vis[a[0]][1] = vis[b[0]][1] = vis[1][b[0]] = true;

	for(int i = 1; i <= N; i ++){
		vis[a[i]][a[i-1]] = vis[a[i-1]][a[i]] = true;
		vis[a[i]][b[i-1]] = vis[b[i-1]][a[i]] = true;
		vis[b[i]][a[i-1]] = vis[a[i-1]][b[i]] = true;
		vis[b[i]][b[i-1]] = vis[b[i-1]][b[i]] = true;

		vis[c[i]][c[i-1]] = vis[c[i-1]][c[i]] = true;
	}

	for(int i = 0; i <= N; i ++)if(x & (1ll << i) ){
		vis[a[i]][c[i]] = vis[c[i]][a[i]] = true;
	}

	vis[c[N]][2] = vis[2][c[N]] = true;

	cout << cnt - 1 << endl;

	for(int i = 1; i <= cnt - 1; i ++){
		for(int j = 1; j <= cnt - 1; j ++){
			if(vis[i][j]) printf("Y");
			else printf("N");
		}puts("");
	}
}