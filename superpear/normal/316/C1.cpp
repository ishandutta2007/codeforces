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
    int dest,flow,cost;
    ljb *next,*other;
} *head[7005],*tail[7005],*p,*pre[7005];

int m,n,uu,rc,fc,ans1,ans2,S,o,v;
int a[105][105],biao[105][105],flag[10005],cost[10005],u[3000005],flow[10005];

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
        ans2+=cost[S]*flow[S];
        uu=S;
        while (uu>0)
        {
            pre[uu]->flow-=flow[S];
            pre[uu]->other->flow+=flow[S];
            uu=pre[uu]->other->dest;
        }
    }
}

void pt(int x,int y,int xc,int yc)
{
	if ((xc<1)||(xc>m)||(yc<1)||(yc>n)) return;
	if (a[x][y]==a[xc][yc]) mpush(biao[x][y],biao[xc][yc],1,0); else 
	mpush(biao[x][y],biao[xc][yc],1,1);	
}

int main()
{
	scanf("%d %d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	o=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0) ++o,biao[i][j]=o;
	v=o;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)%2==1) ++o,biao[i][j]=o;
	S=o+1;
	for (int i=0;i<=S;i++)
	{
		p=new ljb;
		p->dest=0,p->cost=0,p->flow=0;
		p->next=0,p->other=0;
		head[i]=p,tail[i]=p;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0)
			{
				pt(i,j,i-1,j);
				pt(i,j,i,j-1);
				pt(i,j,i,j+1);
				pt(i,j,i+1,j);
			}
	for (int i=1;i<=v;i++) mpush(0,i,1,0);
	for (int i=v+1;i<=o;i++) mpush(i,S,1,0);
	spfa();
	cout<<ans2<<endl;
				
	return 0;
}