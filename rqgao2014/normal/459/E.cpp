#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int u,v,w;
}p[3000005];
int n,m,dp[3000005],end[3000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	sort(p+1,p+m+1,cmp);
	int j=1;
	for(int i=1;i<=m;i++)
	{
		if(p[i].w!=p[i-1].w){
			while(j<i&&j<=m){
				end[p[j].v]=max(end[p[j].v],dp[j]);
				j++;
			}
		}
		dp[i]=end[p[i].u]+1;
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}