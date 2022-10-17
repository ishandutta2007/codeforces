#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node{
	int low,high,cost;
} map[10][10];
int flow[10],minf,maxcost,n;
bool sign;
void dfs(int u,int v,int ncost){
	if(u==n){
		sign=1;
		maxcost=max(maxcost,ncost);
		return;
	}
	for(int nflow=map[u][v].low;nflow<=min(map[u][v].high,flow[u]);nflow++){
		flow[v]+=nflow;
		flow[u]-=nflow;
		int tmp=0;
		if(nflow){
			tmp=nflow*nflow+map[u][v].cost;
		}
		if(v==n&&flow[u]==0){
			dfs(u+1,u+2,ncost+tmp);
		}
		else{
			dfs(u,v+1,ncost+tmp);
		}
		flow[v]-=nflow;
		flow[u]+=nflow;
	}
}
int main(){
	int s,f,l,h,c;
	while(~scanf("%d",&n)){
		memset(map,0,sizeof(map));
		sign=0;
		int sum=(n*(n-1))/2;
		for(int i=0;i<sum;i++){
			scanf("%d%d%d%d%d",&s,&f,&l,&h,&c);
			map[s][f].low=l;
			map[s][f].high=h;
			map[s][f].cost=c;
		}
		int maf,mif;
		maf=mif=0;
		for(int i=2;i<=n;i++){
			maf+=map[1][i].high,mif+=map[1][i].low;
		}
		int ansaf=maf,ansif=mif;
		maf=mif=0;
		for(int i=1;i<n;i++){
			maf+=map[i][n].high,mif+=map[i][n].low;
		}
		ansaf=max(ansaf,maf);
		ansif=min(ansif,mif);
		for(minf=ansif;minf<=ansaf;minf++){
			memset(flow,0,sizeof(flow));
			flow[1]=minf;
			maxcost=0;
			dfs(1,2,0);
			if(sign){
				printf("%d %d\n",minf,maxcost);
				break;
			}
		}
		if(!sign){
			puts("-1 -1");
		}
	}
	return 0;
}