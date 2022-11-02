#include <bits/stdc++.h>
using namespace std;
#define N 200005

int a[N], rt, rlt;
int vis[N], n, b;

void dfs(int k){
	if(vis[k] == 1) a[k] = k, rlt++;
	else if(!vis[k]) vis[k] = 1, dfs(a[k]);
	vis[k] = 2;
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", a + i);
		if(a[i] == i){
			vis[i] = 2;
			rt = i;
			rlt++;
		}
	}
	for(i = 1; i <= n; i++) if(!vis[i]) dfs(i);
	printf("%d\n", rlt - (rt > 0));
	for(i = 1; i <= n; i++){
		if(a[i] == i){
			if(!rt) rt = i;
			a[i] = rt;
		}
		printf("%d", a[i]);
		if(i < n) printf(" ");
	}
}