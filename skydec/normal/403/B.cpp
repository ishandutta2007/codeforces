#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
map<int,int>ls;
int n,m;
int g[5005];
int a[5005];
int gcd(int a,int b){if(!a||!b)return a+b;return gcd(b,a%b);}
int calc(int x)
{
	int res=0;
	for(int i=2;i*i<=x;i++)
	while(x%i==0)
	{
		x/=i;
		if(ls[i])res--;else res++;
	}
	if(x!=1)
	{
		if(ls[x])res--;else res++;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n){scanf("%d",&a[i]);g[i]=gcd(g[i-1],a[i]);}
	rep(j,1,m){int s;scanf("%d",&s);ls[s]=1;}int sum=0;
	per(i,n,1)
	{
		if(calc(g[i])<0)
		{
			rep(j,1,i)a[j]/=g[i],g[j]/=g[i];
		}
		sum+=calc(a[i]);
	}
	printf("%d\n",sum);
	return 0;
}