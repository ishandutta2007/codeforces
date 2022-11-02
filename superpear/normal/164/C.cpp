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
    ljb *next,*other;
    int dest,flow,cost,flag;
} *p,*head[2005],*tail[2005],*pre[2005];

int u[1000005],b[2005],flow[2005],cost[2005],l[2005],r[2005],w[2005],m1[2005],bak[2005];
int n,k,o,s;

void mpush(int x,int y,int z,int w,int flag)
{
    ljb *p,*q;
    p=new ljb;
    p->dest=y,p->flow=z,p->cost=w;
    p->flag=flag;
    p->next=0;
    tail[x]->next=p,tail[x]=p;
    q=new ljb;
    q->dest=x,q->flow=0,q->cost=-w;
    q->flag=0;
    q->next=0;
    tail[y]->next=q,tail[y]=q;
    p->other=q,q->other=p;
}

void spfa()
{
    ljb *p;
    int rc,fc,uu;
    while (true)
    {
        rc=1,fc=1,u[rc]=0;
        for (int i=0;i<=s;i++) flow[i]=0,cost[i]=-maxlongint;
        flow[0]=maxlongint;
        cost[0]=0;
        while (rc<=fc)
        {
            p=head[u[rc]]->next;
            while (p!=0)
            {
                if ((p->flow>0)&&(cost[u[rc]]+p->cost>cost[p->dest]))
                {
                    cost[p->dest]=cost[u[rc]]+p->cost;
                    flow[p->dest]=min(flow[u[rc]],p->flow);
                    pre[p->dest]=p;
                    ++fc,u[fc]=p->dest;
                }
                p=p->next;
            }
            ++rc;
        }
        //cout<<cost[s]<<endl;
        if (cost[s]<0) return;
        uu=s;
        while (uu>0)
        {
            pre[uu]->flow-=flow[s];
            pre[uu]->other->flow+=flow[s];
            uu=pre[uu]->other->dest;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    o=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&l[i],&r[i],&w[i]);
        r[i]+=l[i];
        ++o,bak[o]=l[i],++o,bak[o]=r[i];
    }
    sort(bak+1,bak+o+1);
    m1[1]=1;
    for (int i=2;i<=o;i++)
        if (bak[i]==bak[i-1]) m1[i]=m1[i-1]; else m1[i]=m1[i-1]+1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=o;j++)
            if (l[i]==bak[j])
            {
                l[i]=m1[j];
                break;
            }
        for (int j=1;j<=o;j++)
            if (r[i]==bak[j])
            {
                r[i]=m1[j];
                break;
            }
    }
    //for (int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;
    s=m1[o];
    for (int i=0;i<=s;i++)
    {
        p=new ljb;
        p->next=0,p->other=0;
        p->dest=0,p->cost=0,p->flow=0;
        p->flag=0;
        head[i]=p,tail[i]=p;
    }
    for (int i=1;i<s;i++)
        mpush(i,i+1,maxlongint,0,0);
    mpush(0,1,k,0,0);
    for (int i=1;i<=n;i++)
        mpush(l[i],r[i],1,w[i],i);
    spfa();
    memset(b,0,sizeof(b));
    for (int i=0;i<=s;i++)
    {
        p=head[i]->next;
        while (p!=0)
        {
            if (p->flow==0) b[p->flag]=1;
            p=p->next;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (b[i]==1) printf("1"); else printf("0");
        if (i!=n) printf(" ");
    }
    printf("\n");

    return 0;
}