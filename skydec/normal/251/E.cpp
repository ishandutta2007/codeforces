//Orz wjh720
//Orz zhj
//Orz stilwell
//Orz qiaoranliqu
//Orz Rxdoi
//T_T
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#define jsb 1000000007
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 210000
int n;int head[MAXN],next[MAXN*2],p[MAXN*2],fa[MAXN],son[MAXN][3],hs[MAXN],size[MAXN];
int ds[MAXN];bool h3[MAXN];int tot=0;
int dl[MAXN],dlen[MAXN];
void line(int a,int b)
{
	tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
#define find finds
void build(int x)
{
	if(ds[x]==3)h3[x]=1;hs[x]=0;size[x]=1;
	for(int u=head[x];u;u=next[u])
	if(p[u]!=fa[x])
	{
		son[x][hs[x]++]=p[u];
		fa[p[u]]=x;
		build(p[u]);
		h3[x]|=h3[p[u]];
		size[x]+=size[p[u]];
	}
	if(hs[x]==1)dl[x]=dl[son[x][0]],dlen[x]=dlen[son[x][0]]+1;
	if(hs[x]==2)dl[x]=x,dlen[x]=1;
	if(hs[x]==0)dlen[x]=1;
}
//dp(x):
//dp2(x,y):
int uccu[MAXN];bool find[MAXN];
int dp2(int x,int y);
int dp(int x)
{
	if(!x)return 1;if(find[x])return uccu[x];
	if(size[x]&1)return 0;
	if(!h3[x])return size[x]/2;
	
	if(hs[x]==1){
	
	if(!h3[x])return size[x]/2;
 	if(h3[son[x][0]]&&h3[son[x][1]])return 0;
 	find[x]=1;int p=dl[x];
 	//
 	for(int j=0;j<=1;j++)
 	if(!h3[son[p][j]]&&size[son[p][j]]<dlen[x]-1)
 	uccu[x]=(uccu[x]+dp(son[p][j^1]))%jsb;
 	if(dlen[x]&1)
 	{
 		//if(h3[son[p][0]]&&h3[son[p][1]])return uccu[x];
 		rep(i,0,1)
		{
			int A=son[p][i];
		 	if(!hs[A])uccu[x]=(uccu[x]+dp(son[p][i^1]))%jsb;
		 	if(hs[A]==1)uccu[x]=(uccu[x]+dp2(son[A][0],son[p][i^1]))%jsb;
		 }
 	}
 	rep(i,0,1)
 	{
 		int A=son[p][i];
 		if(hs[A]==1&&size[son[A][0]]<dlen[x]&&!h3[son[A][0]])
		uccu[x]=(uccu[x]+dp(son[p][i^1]))%jsb;
 		if(hs[A]==2)
 		{
 			rep(j,0,1)
 			if(!h3[son[A][j]]&&size[son[A][j]]<dlen[x])uccu[x]=(uccu[x]+dp2(son[p][i^1],son[A][j^1]))%jsb;
		}
	}
	}
	else
	{
		find[x]=1;
		if(size[x]&1)return 0;
		for(int i=0;i<=1;i++)
		{
			if(hs[son[x][i]]==0)uccu[x]=(uccu[x]+dp(son[x][i^1]))%jsb;
			if(hs[son[x][i]]==1)uccu[x]=(uccu[x]+dp2(son[son[x][i]][0],son[x][i^1]))%jsb;
		}
	}
	return uccu[x];
}
int dp2(int x,int y)
{
	bool watch=0;
	if(x==2&&y==5)watch=1;
	if((size[x]+size[y])%2==1)return 0;
	if(h3[x]&&h3[y])return 0;
	while(x&&y)
	{
		if(hs[x]==2)return 0;
		if(hs[y]==2)return 0;
		x=son[x][0];
		y=son[y][0];
	}
	//if(watch)printf("caonima %d %d\n",x,y);
	if(x==0&&y==0)return 1;
	if(hs[x+y]==0)return 0;
	return dp(x+y);
}	
int ans=0;
int Work(int s1,int s2,int s3)
{
	if(hs[s2]==0)return (dp(s1)*1ll*dp(s3))%jsb;
	if(hs[s2]==1)
	{
		int res=0;
		res=(res+dp2(s1,son[s2][0])*1ll*dp(s3))%jsb;
		res=(res+dp2(s3,son[s2][0])*1ll*dp(s1))%jsb;
		return res;
	}
	if(hs[s2]==2)
	{
		int res=0;
		res=(res+dp2(s1,son[s2][0])*1ll*dp2(s3,son[s2][1]))%jsb;
		res=(res+dp2(s1,son[s2][1])*1ll*dp2(s3,son[s2][0]))%jsb;
		return res;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);if(n==1){printf("2\n");return 0;}
	rep(i,1,2*n-1)
	{
		int a,b;scanf("%d%d",&a,&b);
		line(a,b);line(b,a);ds[a]++;ds[b]++;
	}
	int k=0;
	rep(i,1,2*n)
	if(ds[i]>3)
	{
		printf("0\n");
		return 0;
	}
	else if(ds[i]==3)k=i;
	if(!k)
	{
		printf("%d\n",(2ll*n*n-2ll*n+4)%jsb);
		return 0;
	}
	build(k);//printf("%d\n",dp(10));
	//printf("__%d %d\n",h3[10],size[10]);
	ans=(ans+Work(son[k][0],son[k][1],son[k][2]))%jsb;
	ans=(ans+Work(son[k][0],son[k][2],son[k][1]))%jsb;
	ans=(ans+Work(son[k][1],son[k][2],son[k][0]))%jsb;
	ans=(ans+Work(son[k][1],son[k][0],son[k][2]))%jsb;
	ans=(ans+Work(son[k][2],son[k][1],son[k][0]))%jsb;
	ans=(ans+Work(son[k][2],son[k][0],son[k][1]))%jsb;
	printf("%d\n",ans*2%jsb);
	return 0;
}