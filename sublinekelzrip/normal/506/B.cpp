#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
struct Bian
{
    int s,t,last;
}bian[500010];
int last[100010],maxbian=0;
void addbian(int s,int t)
{
    maxbian++;
    bian[maxbian].s=s;
    bian[maxbian].t=t;
    bian[maxbian].last=last[s];
    last[s]=maxbian;
}
stack<int> s;
int dfn[100010],low[100010],ins[100010],maxdfn=0,maxscc=0,scc[100010],sum[100010];
void tarjan(int x)
{
    maxdfn++;
    dfn[x]=low[x]=maxdfn;
    ins[x]=1;
    s.push(x);
    int i;
    for(i=last[x];i;i=bian[i].last)
        if(!dfn[bian[i].t])
        {
            tarjan(bian[i].t);
            low[x]=min(low[x],low[bian[i].t]);
        }
        else
            if(ins[bian[i].t])
                low[x]=min(low[x],dfn[bian[i].t]);
    if(low[x]==dfn[x])
    {
        maxscc++;
        scc[s.top()]=maxscc;
        sum[maxscc]=1;
        ins[s.top()]=0;
        while(s.top()!=x)
        {
            s.pop();
            sum[maxscc]++;
            scc[s.top()]=maxscc;
            ins[s.top()]=0;         
        }
        s.pop();
    }
}
int cd[100010],fa[100010],cda[100010];
int get(int i)
{
    if(fa[i]==i)
        return i;
    else
        return fa[i]=get(fa[i]);
}
int main()
{
    int n,m,n1,m1,t1,t2;
    cin>>n>>m;
    for(m1=1;m1<=m;m1++)
    {
        scanf("%d%d",&t1,&t2);
        addbian(t1,t2);
    }
    for(n1=1;n1<=n;n1++)
        if(!dfn[n1])
            tarjan(n1);
    for(n1=1;n1<=maxscc;n1++)
        fa[n1]=n1;
    for(n1=1;n1<=maxbian;n1++)
        if(scc[bian[n1].s]!=scc[bian[n1].t])
        {
            int i=get(scc[bian[n1].s]);
            fa[i]=get(scc[bian[n1].t]);
        }
    for(n1=1;n1<=maxscc;n1++)
    {
        cd[get(n1)]+=sum[n1];
        if(sum[n1]>1)
        	cda[get(n1)]=1;	
    }
    int ans=0;
    for(n1=1;n1<=maxscc;n1++)
        if(cd[n1]>0)
        {
        	ans+=cd[n1];
        	if(!cda[n1])
        		ans--;
        }
    cout<<ans;
}