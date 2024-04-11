#include <cstdio>
#define Maxn 50
int a[Maxn+5][Maxn+5];
int n,m;
int ans[Maxn*Maxn+5][2];
bool vis[Maxn+5][Maxn+5];
int len;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1&&!vis[i][j]){
				if(a[i][j-1]==1){
					if(a[i+1][j-1]==1&&a[i+1][j]==1){
						ans[++len][0]=i;
						ans[len][1]=j-1;
						vis[i][j]=1;
						vis[i+1][j-1]=1;
						vis[i+1][j]=1;
						continue;
					}
				}
				if(a[i-1][j]==1){
					if(a[i-1][j+1]==1&&a[i][j+1]==1){
						ans[++len][0]=i-1;
						ans[len][1]=j;
						vis[i][j]=1;
						vis[i][j+1]=1;
						continue;
					}
					if(a[i][j-1]==1&&a[i-1][j-1]==1){
						ans[++len][0]=i-1;
						ans[len][1]=j-1;
						vis[i][j]=1;
						continue;
					}
				}
				if(a[i][j+1]==0||a[i+1][j]==0||a[i+1][j+1]==0){
					puts("-1");
					return 0;
				}
				ans[++len][0]=i;
				ans[len][1]=j;
				vis[i][j]=1;
				vis[i][j+1]=1;
				vis[i+1][j]=1;
				vis[i+1][j+1]=1;
			}
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}