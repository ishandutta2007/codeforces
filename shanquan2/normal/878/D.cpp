#include<bits/stdc++.h>
using namespace std;

struct jry{
	int tp,x,y,z;
}q[100015];
int a[13][100015],n,k,m,cnt;
bitset<4105>b[100015];
int main(){
	scanf("%d%d%d",&n,&k,&m);cnt=k+1;
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].tp,&q[i].x,&q[i].y);
		if(q[i].tp!=3)q[i].z=cnt++;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<1<<k;j++)if(j>>i&1)b[i+1][j]=1;
	}
	for(int i=1;i<=m;i++)if(q[i].tp!=3){
		int w=q[i].z,u=q[i].x,v=q[i].y;
		if(q[i].tp==1)b[w]=b[u]|b[v];
		else if(q[i].tp==2)b[w]=b[u]&b[v];
	}
	for(int i=1;i<=m;i++)if(q[i].tp==3){
		int u=q[i].x,v=q[i].y,ans=0;
		for(int j=1;j<=k;j++){
			int s=0,t=a[j][v];
			for(int l=1;l<=k;l++)if(a[l][v]>=t)s|=1<<l-1;
			if(b[u][s])ans=max(ans,t);
		}
		printf("%d\n",ans);
	}
	return 0;
}