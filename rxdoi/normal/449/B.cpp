#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=2e5+19,M=3e5+19+1e5+19;
typedef long long LL;
struct Edge {int x,y,c,Rail,nxt;} E[M<<1];
int vis[Maxn],pre[Maxn],Cho[M<<1],n,Ans,m,k,Last[Maxn],cnt,x,y,z;
LL Dis[Maxn];
int Q[Maxn],f,w,Q_Len;

inline void Add_Edge(int x,int y,int c,int Rail)
{
	E[cnt]=(Edge){x,y,c,Rail,Last[x]};
	Last[x]=cnt++;
}
inline void SPFA()
{
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) Dis[i]=1LL<<60;
    Dis[1]=0;Q[Q_Len=f=1]=1;
    while (Q_Len)
    {
        Q_Len--;int x=Q[w=(w+1)%Maxn];
        for (int i=Last[x];i^-1;i=E[i].nxt)
        {
            int y=E[i].y;
	        if (Dis[x]+E[i].c<Dis[y])
	        {
	        	Dis[y]=Dis[x]+E[i].c;
	        	if (E[pre[y]].Rail) Cho[pre[y]]=0;
	        	pre[y]=i;
	        	if (E[i].Rail) Cho[i]=1;
	        	if (!vis[y]) 
				{
					vis[y]=1;Q_Len++;
					if (Dis[y]<Dis[Q[w+1]]) Q[w--]=y;else Q[f=(f+1)%Maxn]=y;
				}
	        } else
	        if (Dis[x]+E[i].c==Dis[y]&&!E[i].Rail) Cho[pre[y]]=0,pre[y]=i;
        }
        vis[x]=0;
    }
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(Last,-1,sizeof(Last));
	for (int i=0;i<m;i++) 
	{
		scanf("%d%d%d",&x,&y,&z);
		Add_Edge(x,y,z,0);Add_Edge(y,x,z,0);
	}
	for (int i=0;i<k;i++)
	{
		scanf("%d%d",&y,&z);
		Add_Edge(1,y,z,1);
	}
	SPFA();
	for (int i=2*m;i<2*m+k;i++) Ans+=(Cho[i]==0);
	printf("%d\n",Ans);
}