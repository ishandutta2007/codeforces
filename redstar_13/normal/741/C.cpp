#include <bits/stdc++.h>

using namespace std;

#define NN 200010
int ans[NN];
int a[NN],b[NN];
int f[NN];

void dfs(int u,int id){
	ans[u]=id;
	ans[f[u]]=3-id;
	if(u%2==0&&ans[u-1]==0) dfs(u-1,3-id);
	if(u%2==1&&ans[u+1]==0) dfs(u+1,3-id);
	if(f[u]%2==0&&ans[f[u]-1]==0) dfs(f[u]-1,id);
	if(f[u]%2==1&&ans[f[u]+1]==0) dfs(f[u]+1,id);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		f[a[i]]=b[i];
		f[b[i]]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		if(!ans[i]) dfs(i,1);
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",ans[a[i]],ans[b[i]]);
    return 0;
}