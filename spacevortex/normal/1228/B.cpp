#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=1050;
int n,m,ans=1;
int a[N][N];
int main()
{
	int i,j,len;
	scanf("%d%d",&n,&m);
	memset(a,-1,sizeof(a));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&len);
		for(j=1;j<=len;j++) a[i][j]=1;
		a[i][len+1]=0;
	}
	for(j=1;j<=m;j++)
	{
		scanf("%d",&len);
		for(i=1;i<=len;i++)
		{
			if(a[i][j]==0)
			{
				puts("0");return 0;
			}
			a[i][j]=1;
		}
		if(a[len+1][j]==1) 
		{
			puts("0");return 0;
		}
		a[i][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			//printf("#%d %d %d\n",i,j,a[i][j]);
			if(a[i][j]==-1) ans=mul(ans,2);
		}
	}
	printf("%d",ans);
	return 0;
}