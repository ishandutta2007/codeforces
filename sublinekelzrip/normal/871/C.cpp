#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
pair<int,int> num[100010];
map<int,int> x,y;
int fa[100010],is[100010],sz[100010],e[100010];
const int mod=1000000007;
int get(int i)
{
	return fa[i]==i?i:fa[i]=get(fa[i]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		is[i]=0;
		sz[i]=1;
		e[i]=2;
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&num[i].first,&num[i].second);
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	{
		int t;
		if((t=x[num[i].first]))
		{
			int k=get(t);
			fa[i]=k;
			sz[k]++;
			e[k]++;
		}
		x[num[i].first]=i;
		if((t=y[num[i].second]))
		{
			int j=get(t),k=get(i);
			if(j==k)
			{
				is[j]=1;
				e[j]--;
			}
			else
			{
				fa[k]=j;
				sz[j]+=sz[k];
				is[j]|=is[k];
				e[j]=e[j]+e[k]-1;
			}
		}		
		y[num[i].second]=i;		
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
		{
			long long now=1;
			for(int j=1;j<=e[i];j++)
				now=now*2%mod;
			if(is[i]==0)
				now--;
			ans=ans*now%mod;
		}
	cout<<ans<<endl;
}