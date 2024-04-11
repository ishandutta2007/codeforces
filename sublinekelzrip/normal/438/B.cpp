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
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int fa[100010],sz[100010];
int get(int i)
{
	return fa[i]==i?i:fa[i]=get(fa[i]);
}
struct Bian
{
	int t,last;
}bian[200010];
int last[100010],maxbian=0;
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
typedef pair<int,int> pii;
pii f[100010];
int p[100010];
int main()
{
	int n,m,n1,m1;
	cin>>n>>m;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&f[n1].first);
		p[n1]=f[n1].first;
		fa[n1]=n1;
		sz[n1]=1;
		f[n1].second=n1;
	}
	int a,b;
	for(m1=1;m1<=m;m1++)
	{
		scanf("%d%d",&a,&b);
		addbian(a,b);
		addbian(b,a);
	}
	sort(f+1,f+n+1);
	double ans=0;
	for(n1=n;n1>=1;n1--)
	{
		for(m1=last[f[n1].second];m1;m1=bian[m1].last)
		{
			if(get(bian[m1].t)!=get(f[n1].second))
				if(f[n1].first<p[bian[m1].t]||((f[n1].first==p[bian[m1].t])&&f[n1].second<bian[m1].t))
				{
					ans+=(long long)f[n1].first*(long long)sz[get(f[n1].second)]*(long long)sz[get(bian[m1].t)];
					sz[get(bian[m1].t)]+=sz[get(f[n1].second)];
					sz[get(f[n1].second)]=0;
					fa[get(f[n1].second)]=get(bian[m1].t);
				}
		}
	}
	ans/=(long long)n*(long long)(n-1)/2;
	cout<<ans;
}