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
    int dest,cost;
    ljb *next;
};

struct three
{
    int num,start,over;
};

ljb *p,*head[120000],*tail[120000];
int m,n,o,kc,e,rc,fc;
int dis[120000],u[10000000],l[120000],r[120000],ls[120000],flag[120000];
three f[550000];

void push(int x,int y,int z)
{
    ljb *p;
    p=new ljb;
    p->dest=y;p->cost=z;p->next=0;
    tail[x]->next=p;tail[x]=p;
}

bool cmp(three x,three y)
{
    if (x.num<y.num) return true;
    if (x.num>y.num) return false;
    if (x.start<y.start) return true; else return false;
}

int getqtime(int s,int t)
{
    if (l[s]==-1) return t;
    int left,right,mid;
    left=l[s];right=r[s];
    while (left<=right)
    {
        mid=(left+right)/2;
        if (f[mid].over>=t) right=mid-1; else left=mid+1;
    }
    if (left>r[s]) return t;
    if (f[left].start<=t) return f[left].over+1; else return t;
}

int main()
{
    int x1,y1,z1,ee=0;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        p=new ljb;
        p->dest=0;p->cost=0;p->next=0;
        head[i]=p;tail[i]=p;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x1,&y1,&z1);
        push(x1,y1,z1);
        push(y1,x1,z1);
    }
    o=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&kc);
        if (kc==0)
        {
            l[i]=-1;
            r[i]=-1;
            continue;
        }
        for (int j=1;j<=kc;j++) scanf("%d",&ls[j]);
        if (i==1)
        {
            for (int j=1;j<=kc;j++)
                if (j-1!=ls[j])
                {
                    ee=j-1;break;
                }
            ee=kc;
        }
        ++kc;ls[kc]=maxlongint;
        e=1;
        for (int j=2;j<=kc;j++)
            if (ls[j]!=ls[j-1]+1)
            {
                ++o;f[o].num=i;f[o].start=ls[e];f[o].over=ls[j-1];
                e=j;
            }
    }
    sort(f+1,f+o+1,cmp);
    f[0].num=0;
    for (int i=1;i<=o;i++)
        if (f[i].num!=f[i-1].num)
        {
            r[f[i-1].num]=i-1;
            l[f[i].num]=i;
        }
    r[f[o].num]=o;
    rc=1;fc=1;
    for (int i=1;i<=n;i++) dis[i]=maxlongint;
    memset(flag,0,sizeof(flag));
    dis[1]=0;
    u[1]=1;
    while (rc<=fc)
    {
        flag[u[rc]]=0;
        p=head[u[rc]]->next;
        while (p!=0)
        {
            e=getqtime(u[rc],dis[u[rc]])+p->cost;
            if (e<dis[p->dest])
            {
                dis[p->dest]=e;
                if (flag[p->dest]==0)
                {
                    flag[p->dest]=1;
                    ++fc;u[fc]=p->dest;
                }
            }
            p=p->next;
        }
        ++rc;
    }
    if (dis[n]==maxlongint) cout<<"-1"<<endl; else cout<<dis[n]<<endl;

    return 0;
}