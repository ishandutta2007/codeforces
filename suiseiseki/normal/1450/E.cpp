#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200;
const int Maxm=2000;
const int Inf=0x3f3f3f3f;
int n,m;
int dis[Maxn+5][Maxn+5];
int u[Maxm+5],v[Maxm+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dis[i][j]=0;
			}
			else{
				dis[i][j]=Inf;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		::u[i]=u;
		::v[i]=v;
		if(x){
			dis[u][v]=min(dis[u][v],1);
			dis[v][u]=min(dis[v][u],-1);
		}
		else{
			dis[u][v]=min(dis[u][v],1);
			dis[v][u]=min(dis[v][u],1);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				if(dis[i][j]<-n){
					puts("NO");
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i][i]<0){
			puts("NO");
			return 0;
		}
	}
	int max_u=1,max_v=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[max_u][max_v]<dis[i][j]){
				max_u=i;
				max_v=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(dis[max_u][u[i]]==dis[max_u][v[i]]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%d\n",dis[max_u][max_v]);
	for(int i=1;i<=n;i++){
		printf("%d ",dis[max_u][i]);
	}
	puts("");
	return 0;
}