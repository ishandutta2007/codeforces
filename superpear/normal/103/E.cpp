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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=605;

struct ljb
{
    int dest,flow;
    ljb *next,*other;
} *head[maxn],*tail[maxn],*p;

int n,s,cost,cs,ct,all;
int f[maxn][maxn],vis[maxn],last[maxn],cc[maxn];

void mpush(int x,int y,int w)
{
    //cout<<x<<" "<<y<<" "<<w<<endl;
    ljb *p,*q;
    p=new ljb;
    p->dest=y;p->flow=w;
    p->next=0;
    tail[x]->next=p;
    tail[x]=p;
    q=new ljb;
    q->dest=x;q->flow=0;
    q->next=0;
    tail[y]->next=q;
    tail[y]=q;
    p->other=q;
    q->other=p;
}

int maxflow()
{
    ljb *vi[maxn],*hu[maxn],*mink,*p;
    int flow[maxn],vh[maxn],dis[maxn];
    int arg,i,ans,minc;
    bool flag;

    for (int i=0;i<=s;i++) vi[i]=head[i]->next;
    arg=maxlongint;
    memset(flow,0,sizeof(flow));
    flow[0]=maxlongint;
    memset(vh,0,sizeof(vh));
    vh[0]=s+1;
    memset(dis,0,sizeof(dis));
    i=0;
    ans=0;
    while (dis[0]<=s+1)
    {
        flag=true;
        p=vi[i];
        while (p!=0)
        {
            if ((dis[i]==dis[p->dest]+1)&&(p->flow>0))
            {
                flag=false;
                arg=min(arg,p->flow);
                flow[p->dest]=arg;
                hu[p->dest]=p;
                vi[i]=p;
                i=p->dest;
                if (i==s)
                {
                    ans+=arg;
                    while (i>0)
                    {
                        hu[i]->flow-=arg;
                        hu[i]->other->flow+=arg;
                        i=hu[i]->other->dest;
                    }
                    arg=maxlongint;
                }
                break;
            }
            p=p->next;
        }
        if (flag)
        {
            minc=s+1;
            mink=0;
            p=head[i]->next;
            while (p!=0)
            {
                if ((dis[p->dest]+1<minc)&&(p->flow>0))
                {
                    minc=dis[p->dest]+1;
                    mink=p;
                }
                p=p->next;
            }
            vi[i]=mink;
            --vh[dis[i]];
            if (vh[dis[i]]==0) break;
            dis[i]=minc;
            ++vh[dis[i]];
            if (i!=0)
            {
                i=hu[i]->other->dest;
                arg=flow[i];
            }
        }
    }
    return ans;
}

bool dfs(int s)
{
    vis[s]=1;
    for (int i=n+1;i<=n*2;i++)
        if ((vis[i]==0)&&(f[s][i]==1))
        {
            vis[i]=1;
            if ((last[i]==0)||(dfs(last[i])))
            {
                last[i]=s;
                return true;
            }
        }
    return false;
}
int main()
{
    //freopen("E3.in","r",stdin);
    cin>>n;
    s=n+1;
    for (int i=0;i<=s;i++)
    {
        p=new ljb;
        p->dest=0;p->flow=0;
        p->next=0;p->other=0;
        head[i]=p;
        tail[i]=p;
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cs);
        for (int j=1;j<=cs;j++)
        {
            scanf("%d",&ct);
            f[i][ct+n]=1;
        }
    }
    memset(last,0,sizeof(last));
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        dfs(i);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ((f[i][j+n]==1)&&(last[j+n]!=i)) mpush(i,last[j+n],maxlongint);
    all=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cost);
        if (cost<0)
        {
            all+=-cost;
            mpush(0,i,-cost);
        }
        else
            mpush(i,s,cost);
    }
    cout<<maxflow()-all<<endl;

    return 0;
}