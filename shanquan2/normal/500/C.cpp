#include<cstdio>
#include<cstring>
using namespace std;

int w[500],wei[500]={0};
bool vis[500][500];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&w[i]);
	int ans=0;
	for(int i=0;i<m;i++){
		int x;scanf("%d",&x);x--;
		for(int i=0;i<n;i++)
			if(i==x){
				ans+=wei[i];
				wei[i]=0;
				memset(vis[i],0,sizeof(vis[i]));
			}else{
				if(!vis[i][x])vis[i][x]=1,wei[i]+=w[x];
			}
	}
	printf("%d\n",ans);
	return 0;
}