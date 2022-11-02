#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

struct ljb
{
    int dest,flow,cost;
    ljb *next,*other;
} *head[3005],*tail[3005],*p,*pre[3005];

int N,K,S,ans1,ans2,rc,fc,uu,flag[1005],flow[1005],u[1000005],cost[1005];
int a[55][55];

void mpush(int x,int y,int flow,int cost)
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

void spfa()
{
    ans1=0;
    ans2=0;
    while (true)
    {
        memset(flag,0,sizeof(flag));
        for (int i=0;i<=S;i++) cost[i]=maxlongint;
        cost[0]=0;
        rc=1,fc=1,u[rc]=0;
        memset(flow,0,sizeof(flow));
        flow[0]=maxlongint;
        while (rc<=fc)
        {
            flag[u[rc]]=0;
            p=head[u[rc]]->next;
            while (p!=0)
            {
                if ((p->flow>0)&&(cost[u[rc]]+p->cost<cost[p->dest]))
                {
                	flow[p->dest]=min(flow[u[rc]],p->flow);
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
        if (cost[S]==maxlongint) break;
        ans1+=flow[S];
        uu=S;
        while (uu>0)
        {
            pre[uu]->flow-=flow[S];
            pre[uu]->other->flow+=flow[S];
            uu=pre[uu]->other->dest;
        }
    }
}


void spfa2()
{
    while (true)
    {
        memset(flag,0,sizeof(flag));
        for (int i=0;i<=S;i++) cost[i]=maxlongint;
        cost[0]=0;
        rc=1,fc=1,u[rc]=0;
        memset(flow,0,sizeof(flow));
        flow[0]=maxlongint;
        while (rc<=fc)
        {
            flag[u[rc]]=0;
            p=head[u[rc]]->next;
            while (p!=0)
            {
                if ((p->flow>0)&&(cost[u[rc]]+p->cost<cost[p->dest]))
                {
                	flow[p->dest]=min(flow[u[rc]],p->flow);
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
        if (cost[S]==maxlongint) break;
        if (ans2+cost[S]>K) return;
        ans1+=1;
        ans2+=cost[S];
        uu=S;
        while (uu>0)
        {
            pre[uu]->flow-=1;
            pre[uu]->other->flow+=1;
            uu=pre[uu]->other->dest;
        }
    }
}

int main()
{
	scanf("%d %d",&N,&K);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			scanf("%d",&a[i][j]);
	S=N;
    //S is the total number of nodes in Maxflow graph
    //0 is source and S is sink
    for (int i=0;i<=S;i++)
    {
        p=new ljb;
        p->dest=0,p->flow=0;
        p->next=0,p->other=0,p->cost=0;
        head[i]=p,tail[i]=p;
    }
    mpush(0,1,maxlongint,0);
    for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			if (a[i][j]>0)
				mpush(i,j,a[i][j],0);
	spfa();
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			if (a[i][j]>0)
				mpush(i,j,K,1);
	spfa2();
	cout<<ans1<<endl;

    return 0;
}