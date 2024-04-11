#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef pair<int,int> pi;
int n,w,h,g[N],p[N],t,st1[N],st2[N];
pi ans[N];
inline pi cal(int x)
{
	if(g[x]==1)return{p[x],h};
	return{w,p[x]};
}
vector<int>v[N<<1];
bool cmp1(int x,int y)
{return g[x]==g[y]?g[x]==1?p[x]<p[y]:p[x]>p[y]:g[x]<g[y];}
bool cmp2(int x,int y)
{return g[x]==g[y]?g[x]==1?p[x]<p[y]:p[x]>p[y]:g[x]>g[y];}
int main()
{
    scanf("%d%d%d",&n,&w,&h);
    for(int i=0;i<n;i++)
	scanf("%d%d%d",g+i,p+i,&t),
	v[p[i]-t+N].push_back(i);
	for(int i=0;i<N<<1;i++)
	if(t=v[i].size())
	{
		for(int j=0;j<t;j++)
		st1[j]=st2[j]=v[i][j];
		sort(st1,st1+t,cmp1);
		sort(st2,st2+t,cmp2);
		for(int j=0;j<t;j++)
		ans[st2[j]]=cal(st1[j]);
	}
	for(int i=0;i<n;i++)
	printf("%d %d\n",ans[i].first,ans[i].second);
}