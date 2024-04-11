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
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

struct ljb
{
    int dest,flow;
    double cost;
    ljb *next,*other;
} *head[1005],*tail[1005],*p,*pre[1005];

double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void push(int x,int y,int flow,double cost)
{
    ljb *p,*q;
    p=new ljb;
    p->next=0;
    p->dest=y,p->flow=flow,p->cost=cost;
    tail[x]->next=p,tail[x]=p;
    q=new ljb;
    q->next=0;
    q->dest=x,q->flow=0,q->cost=-cost;
    tail[y]->next=q,tail[y]=q;
    p->other=q,q->other=p;
}

int n,s,ans1,rc,fc,uu,x[1005],y[1005],flag[1005],u[500005];
double ans2,cost[1005];

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    s=n*2+1;
    for (int i=0;i<=s;i++)
    {
        p=new ljb;
        p->next=0;
        p->dest=0,p->flow=0,p->cost=0;
        p->other=0;
        head[i]=p,tail[i]=p;
    }
    for (int i=1;i<=n;i++)
        push(0,i,2,0);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (y[i]>y[j])
                push(i,j+n,1,dist(x[i],y[i],x[j],y[j]));
    for (int i=n+1;i<=n*2;i++)
        push(i,s,1,0);

    ans1=0;
    ans2=0;
    while (true)
    {
        memset(flag,0,sizeof(flag));
        for (int i=0;i<=s;i++) cost[i]=1e10;
        cost[0]=0;
        rc=1,fc=1,u[rc]=0;
        while (rc<=fc)
        {
            flag[u[rc]]=0;
            p=head[u[rc]]->next;
            while (p!=0)
            {
                if ((p->flow>0)&&(cost[u[rc]]+p->cost<cost[p->dest]))
                {
                    cost[p->dest]=cost[u[rc]]+p->cost;
                    pre[p->dest]=p;
                    if (flag[p->dest]==0)
                    {
                        flag[p->dest]=1;
                        ++fc,u[fc]=p->dest;
                    }
                }
                p=p->next;
            }
            ++rc;
        }
        if (cost[s]>1e9) break;
        ans1++;
        ans2+=cost[s];
        uu=s;
        while (uu>0)
        {
            pre[uu]->flow--;
            pre[uu]->other->flow++;
            uu=pre[uu]->other->dest;
        }
    }
    if (ans1!=n-1) printf("-1\n"); else printf("%.10lf\n",ans2);

    return 0;
}