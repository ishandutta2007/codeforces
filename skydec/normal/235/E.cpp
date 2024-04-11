#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef unsigned long long ULL;
#define jsb 1073741824
int N=2000;
int p[1005];int pr[2005];
map<ULL,int>f[520];
int dfs(int a,int b,int c,int up)
{
	if(a<b)swap(a,b);if(a<c)swap(a,c);if(b<c)swap(b,c);
	if(!c)return 0;if(a==1)return 1;if(!up)return 1;
	if(f[up].count(1ll*a*N*N+b*N+c))return f[up][1ll*a*N*N+b*N+c];
	int res=0;int t1,t2,t3;t1=t2=t3=0;
	for(int i=a,t1=0;i;i/=p[up],t1++)
	for(int j=b,t2=0;j;j/=p[up],t2++)
	for(int k=c,t3=0;k;k/=p[up],t3++)
	res=(res+(t1+t2+t3+1)*1ll*dfs(i,j,k,up-1))%jsb;
	f[up][1ll*a*N*N+b*N+c]=res;
	return res;
}
int main()
{
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	rep(i,2,N)if(!pr[i])
	{
		p[++p[0]]=i;
		rep(j,1,N/i)pr[i*j]=1;
	}
	printf("%d\n",dfs(a,b,c,p[0])%jsb);
	return 0;
}