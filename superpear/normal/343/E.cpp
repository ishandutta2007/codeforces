#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <ctime>

using namespace std;

#define LL long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
typedef pair<double,double> PDD;
typedef pair<string,int> PSI;

const int maxlongint=2147483647;
const int biglongint=2139062143;

struct ljb
{
    int dest,flow;
    ljb *next,*other;
} *p,*head[1800],*tail[1800],*vi[1800],*back[1800];

int dist[1800],vh[1800],flow[1800],x[3800],y[3800],z[3800],biao[1800],u[1000005],next[1005];
int f[205][205];
int n,m,S,rc,fc,tt,sc,q,ans;

void mpush(int x,int y,int w)
{
    ljb *p,*q;
    p=new ljb;
    p->dest=y,p->flow=w;
    p->next=0;
    tail[x]->next=p,tail[x]=p;
    q=new ljb;
    q->dest=x,q->flow=w;
    q->next=0;
    tail[y]->next=q,tail[y]=q;
    p->other=q,q->other=p;
}

int getSAP(int S,int ss,int tt)
{
    memset(dist,0,sizeof(dist));
    for (int i=0;i<=S;i++) vi[i]=head[i]->next;
    memset(vh,0,sizeof(vh));
    memset(flow,0,sizeof(flow));

    int arg=maxlongint,e=ss,uu,minc;
    int ttflow=0;
    bool flag;
    ljb *p,*mink;

    while (dist[ss]<=S)
    {
        flow[e]=arg;
        flag=false;
        p=vi[e];
        while (p!=0)
        {
            if ((p->flow>0)&&(dist[p->dest]+1==dist[e]))
            {
                flag=true;
                back[p->dest]=p;
                arg=min(arg,p->flow);
                vi[e]=p;
                e=p->dest;
                if (e==tt)
                {
                    ttflow+=(LL)arg;
                    uu=tt;
                    while (uu!=ss)
                    {
                        back[uu]->flow-=arg;
                        back[uu]->other->flow+=arg;
                        uu=back[uu]->other->dest;
                    }
                    e=ss;
                    arg=maxlongint;
                }
                break;
            }
            p=p->next;
        }
        if (flag==false)
        {
            p=head[e]->next;
            minc=S,mink=0;
            while (p!=0)
            {
                if ((p->flow>0)&&(dist[p->dest]<minc)) minc=dist[p->dest],mink=p;
                p=p->next;
            }
            vi[e]=mink;
            --vh[dist[e]];
            if (vh[dist[e]]==0) break;
            dist[e]=minc+1;
            ++vh[dist[e]];
            if (e!=ss)
            {
                e=back[e]->other->dest;
                arg=flow[e];
            }
        }
    }
    return ttflow;
}

void doit(vector<int> v)
{
    if (v.size()<=1) return;
    S=n;
    for (int i=0;i<=S;i++)
    {
        p=new ljb;
        p->dest=0,p->flow=0;
        p->next=0,p->other=0;
        head[i]=p,tail[i]=p;
    }
    for (int i=1;i<=m;i++)
        mpush(x[i],y[i],z[i]);
    int ss=v[0],tt=v[1];
    int gj=getSAP(S,ss,tt);
    memset(biao,0,sizeof(biao));
    rc=1,fc=1,u[rc]=ss,biao[ss]=1;
    while (rc<=fc)
    {
        p=head[u[rc]]->next;
        while (p!=0)
        {
            if ((p->flow>0)&&(biao[p->dest]==0))
            {
                biao[p->dest]=1;
                ++fc,u[fc]=p->dest;
            }
            p=p->next;
        }
        ++rc;
    }
    //for (int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ((biao[i]==0)&&(biao[j]==1))
            {
                f[i][j]=min(f[i][j],gj);
                f[j][i]=min(f[j][i],gj);
            }
    vector<int> v1,v2;
    for (int i=0;i<v.size();i++)
        if (biao[v[i]]==0) v1.p_b(v[i]); else v2.p_b(v[i]);
    doit(v1);
    doit(v2);
}

vector<int> cmb(vector<int> v)
{
    if (v.size()==1) return v;
    int minc=maxlongint;
    for (int i=0;i<v.size();i++)
        for (int j=0;j<v.size();j++)
            if (i!=j)
                minc=min(minc,f[v[i]][v[j]]);
    vector<int> v0,v1;
    v0.clear();
    int use[205];
    memset(use,0,sizeof(use));
    for (int i=0;i<v.size();i++)
        if (use[i]==0)
        {
            use[i]=1;
            v1.clear();
            v1.p_b(v[i]);
            for (int j=i+1;j<v.size();j++)
                if (f[v[i]][v[j]]>minc)
                {
                    use[j]=1;
                    v1.p_b(v[j]);
                }
            v1=cmb(v1);
            for (int j=0;j<v1.size();j++) v0.p_b(v1[j]);
            if (v0.size()!=v.size()) next[v1[v1.size()-1]]=minc;
        }
    return v0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
    memset(f,127,sizeof(f));
    vector<int> v;
    for (int i=1;i<=n;i++) v.p_b(i);
    doit(v);

    memset(next,0,sizeof(next));
    v.clear();
    for (int i=1;i<=n;i++) v.p_b(i);
    v=cmb(v);

    int ans=0;
    for (int i=1;i<=n;i++) ans+=next[i];
    printf("%d\n",ans);
    for (int i=1;i<n;i++) printf("%d ",v[i-1]);printf("%d\n",v[n-1]);

    return 0;
}