#include <cstdio>
#include <cstring>
int n,m,w[505],p[1005],vis[505],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof vis);
		scanf("%d",&p[i]);
		for(int j=i-1;j>0&&p[i]!=p[j];j--){
			if(!vis[p[j]]){
				vis[p[j]]=1;
				ans+=w[p[j]];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}