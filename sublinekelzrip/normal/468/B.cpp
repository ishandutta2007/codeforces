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
const int maxlongint=2147483647;
const int inf=1000000000;
int fa[100010];
int get(int i)
{
	return fa[i]==i?i:fa[i]=get(fa[i]);
}
map<int,int> mp;
int pr[100010],num[100010];
vector<int>v[100010];
int main()
{
	int n,a,b,n1;
	cin>>n>>a>>b;
	for(n1=1;n1<=n;n1++)
		fa[n1]=n1;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&num[n1]);
		mp[num[n1]]=n1;
	}
	for(n1=1;n1<=n;n1++)
	{
		if(mp[a-num[n1]])
		{
			int k=get(n1),j=get(mp[a-num[n1]]);
			if(k!=j)
				fa[k]=j;
		}
		if(mp[b-num[n1]])
		{
			int k=get(n1),j=get(mp[b-num[n1]]);
			if(k!=j)
				fa[k]=j;
		}
	}
	for(n1=1;n1<=n;n1++)
		v[get(n1)].push_back(n1);
	for(n1=1;n1<=n;n1++)
	{
		int sz=v[n1].size();
		int x=1,y=1;
		for(int i=0;i<sz;i++)
		{
			if(!mp[a-num[v[n1][i]]])
				x=0;
			if(!mp[b-num[v[n1][i]]])
				y=0;
		}
		if(x==1)
			for(int i=0;i<sz;i++)
				pr[v[n1][i]]=0;
			else
				if(y==1)
					for(int i=0;i<sz;i++)
						pr[v[n1][i]]=1;
				else
				{
					printf("NO\n");
					return 0;
				}
	}
	printf("YES\n");
	for(n1=1;n1<=n;n1++)
		printf("%d ",pr[n1]);
						
}