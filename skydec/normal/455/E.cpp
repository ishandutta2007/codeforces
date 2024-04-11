#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define MAXN 110000
using namespace std;
typedef long long LL;
int f[MAXN];int sum[MAXN];
inline LL up(int k,int j)
{
	//printf("orz %d %d %d\n",k,j,f[k]-f[j]);
	return (LL)f[k]-f[j];
}
inline LL down(int k,int j)
{
	//printf("orzrzz %d %d %d\n",k,j,(LL)sum[k]-sum[k-1]-(sum[j]-sum[j-1]));
	return (LL)sum[k]-sum[k-1]-(sum[j]-sum[j-1]);
}
//int f[MAXN];int sum[MAXN];
int q[MAXN];
int n,m;
struct que
{
	int x,y,id;
	void read(int p)
	{
		id=p;scanf("%d%d",&x,&y);
	}
}tmp;
vector<que> head[MAXN];
int ans[MAXN];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&sum[i]);sum[i]+=sum[i-1];}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)tmp.read(i),head[tmp.y].pb(tmp);
	for(int i=1;i<=n;i++)f[i]=i*(sum[i]-sum[i-1])-sum[i];
}
inline int find(int C)
{
	int l,r;int reu=q[0];
	l=1;r=q[0]-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(C*1ll*((sum[q[mid]]-sum[q[mid]-1])-(sum[q[mid+1]]-sum[q[mid+1]-1]))<=-f[q[mid]]+f[q[mid+1]])
		reu=mid,r=mid;else l=mid+1;
	}
	int mid=l;
	if(C*1ll*((sum[q[mid]]-sum[q[mid]-1])-(sum[q[mid+1]]-sum[q[mid+1]-1]))<=-f[q[mid]]+f[q[mid+1]])
	reu=mid;
	return q[reu];
}
inline int biu(int C)
{
	int l,r;int reu=q[0];
	l=1;r=q[0]-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(C*1ll*((sum[q[mid]]-sum[q[mid]-1])-(sum[q[mid+1]]-sum[q[mid+1]-1]))<-f[q[mid]]+f[q[mid+1]])
		reu=mid,r=mid;else l=mid+1;
	}
	int mid=l;
	if(C*1ll*((sum[q[mid]]-sum[q[mid]-1])-(sum[q[mid+1]]-sum[q[mid+1]-1]))<=-f[q[mid]]+f[q[mid+1]])
	reu=mid;
	return q[reu];
}
void work()
{
	for(int i=1;i<=n;i++)
	{
		while(q[0]&&sum[q[q[0]]]-sum[q[q[0]]-1]>sum[i]-sum[i-1])q[0]--;
		while(q[0]>1&&up(q[q[0]],q[q[0]-1])*down(q[q[0]],i)<=up(i,q[q[0]])*down(q[q[0]-1],q[q[0]]))q[0]--;
		//printf("_%d\n",up(3,1)*down(3,5));
		q[++q[0]]=i;
		//for(int is=1;is<=q[0];is++)
		//printf("%d ",q[is]);
		//printf("\n");
		for(int j=0;j<head[i].size();j++)
		{
			int p=find(head[i][j].x-head[i][j].y);
			int p2=biu(head[i][j].x-head[i][j].y);
			ans[head[i][j].id]=sum[head[i][j].y]-sum[p]+(head[i][j].x-head[i][j].y+p)*(sum[p]-sum[p-1]);
			p=p2;
			if(sum[head[i][j].y]-sum[p]+(head[i][j].x-head[i][j].y+p)*(sum[p]-sum[p-1])<ans[head[i][j].id])
			ans[head[i][j].id]=sum[head[i][j].y]-sum[p]+(head[i][j].x-head[i][j].y+p)*(sum[p]-sum[p-1]);
		}
	}
}
void output()
{
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}	
int main()
{
	init();
	work();
	output();
	//for(;;);
	return 0;
}