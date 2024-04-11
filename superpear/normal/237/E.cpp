#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

struct ljb
{
    int dest,flow,cost;
    ljb *next,*other;
};

int n,s,ans1,ans2,flag[10000],cost[10000],flow[10000],u[100000],hh[10000],lim[10000];
ljb *p,*head[10000],*tail[10000],*hu[10000];
string ct,cs[10000];

void push(int x,int y,int z,int w)
{
    ljb *p,*q;
    p=new ljb;
    p->dest=y;p->flow=z;p->cost=w;
    p->next=0;tail[x]->next=p;tail[x]=p;
    q=new ljb;
    q->dest=x;q->flow=0;q->cost=-w;
    q->next=0;tail[y]->next=q;tail[y]=q;
    p->other=q;q->other=p;
}

void spfa()
{
    int rc,fc,uu;
    ljb *p;
    while (true)
    {
        memset(flow,0,sizeof(flow));
        for (int i=0;i<=s;i++) cost[i]=maxlongint;
        memset(flag,0,sizeof(flag));
        cost[0]=0;
        flow[0]=maxlongint;
        rc=1;fc=1;u[rc]=0;
        while (rc<=fc)
        {
            flag[u[rc]]=0;
            p=head[u[rc]]->next;
            while (p!=0)
            {
                if ((p->flow>0)&&(cost[u[rc]]+p->cost<cost[p->dest]))
                {
                    cost[p->dest]=cost[u[rc]]+p->cost;
                    flow[p->dest]=min(flow[u[rc]],p->flow);
                    hu[p->dest]=p;
                    if (flag[p->dest]==0)
                    {
                        ++fc;u[fc]=p->dest;
                        flag[p->dest]=1;
                    }
                }
                p=p->next;
            }
            ++rc;
        }
        if (flow[s]==0) break;
        ans1+=flow[s];
        ans2+=flow[s]*cost[s];
        uu=s;
        while (uu!=0)
        {
            hu[uu]->flow-=flow[s];
            hu[uu]->other->flow+=flow[s];
            uu=hu[uu]->other->dest;
        }
    }
}

int main()
{
    string ct;
    cin>>ct;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>cs[i]>>lim[i];
    s=n+27;
    for (int i=0;i<=s;i++)
    {
        p=new ljb;
        p->dest=0;p->cost=0;p->flow=0;
        p->next=0;p->other=0;
        head[i]=p;tail[i]=p;
    }
    for (int i=1;i<=n;i++) push(0,i,lim[i],0);
    for (int i=1;i<=n;i++)
    {
        memset(hh,0,sizeof(hh));
        for (int j=0;j<cs[i].size();j++) ++hh[cs[i][j]-96];
        for (int j=1;j<=26;j++) push(i,j+n,hh[j],i);
    }
    memset(hh,0,sizeof(hh));
    for (int i=0;i<ct.size();i++) ++hh[ct[i]-96];
    for (int i=1;i<=26;i++) push(i+n,s,hh[i],0);
    spfa();
    if (ans1!=ct.size()) ans2=-1;
    cout<<ans2<<endl;

    return 0;
}