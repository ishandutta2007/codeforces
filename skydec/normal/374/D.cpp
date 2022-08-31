#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define drep(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 1100000
int sum[MAXN*4];int use[MAXN];int len;int n,m;int a[MAXN];int nwz=0;
int val[MAXN*4];
int pos[MAXN];
void add(int x,int v,int biu)
{
	int u=pos[x];sum[u]+=biu;val[x]=v;u/=2;
	while(u)sum[u]=sum[u*2]+sum[u*2+1],u/=2;
}
int askk(int now,int l,int r,int x)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(x<=sum[now*2])return askk(now*2,l,mid,x);
	else return askk(now*2+1,mid+1,r,x-=sum[now*2]);
}
void xianzhuo()
{
	drep(i,use[len],1)
	{
		int p=a[i];
		add(askk(1,1,n,p),1,-1);
	}
	len-=use[len];
}
void build(int now,int l,int r)
{
	if(l==r){pos[l]=now;return;}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);len=0;build(1,1,n);
	rep(i,1,m)scanf("%d",&a[i]);a[0]=0;a[m+1]=1000001;
	rep(i,0,m)rep(j,a[i],a[i+1]-1)use[j]=i;
	rep(fz,1,n)
	{
		int v;scanf("%d",&v);
		if(v==-1&&len)xianzhuo();
		else if(v!=-1)add(++nwz,v,1),len++;
	}
	if(!len)printf("Poor stack!\n");
	else rep(i,1,len)printf("%d",val[askk(1,1,n,i)]);
	return 0;
}