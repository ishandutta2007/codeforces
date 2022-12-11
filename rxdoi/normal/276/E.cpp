#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
struct Edge {int y,nxt;} E[Maxn*2];
int n,Q,x,y,v,d,Ecnt,now,type,cnt,Ans1;
int C[Maxn],Cr[Maxn];
int Fir[Maxn],Last[Maxn],D[Maxn],B[Maxn];

inline void Add_r(int x,int v) {while (x<=n) Cr[x]+=v,x+=x&-x;}
inline int Sum_r(int x) {int Ans=0;while (x) Ans+=Cr[x],x-=x&-x;return Ans;}
inline void Add(int x,int v) {while (x<=n) C[x]+=v,x+=x&-x;}
inline int Sum(int x) {int Ans=0;while (x) Ans+=C[x],x-=x&-x;return Ans;}

inline void Link(int x,int y)
{
	E[Ecnt]=(Edge){y,Last[x]};Last[x]=Ecnt++;
	E[Ecnt]=(Edge){x,Last[y]};Last[y]=Ecnt++;
}
inline void DFS(int x,int Fa,int Deep,int Bel)
{
	++now;
	D[x]=Deep;B[x]=Bel;
	for (int i=Last[x];i!=-1;i=E[i].nxt)
		if (E[i].y!=Fa) DFS(E[i].y,x,Deep+1,Bel);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&Q);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Link(x,y);
	for (int i=Last[1];i!=-1;i=E[i].nxt)
	{
		Fir[++cnt]=++now;
		DFS(E[i].y,1,1,cnt);now--;
	}
	Fir[cnt+1]=n;
	while (Q--)
	{
		scanf("%d",&type);
		if (type==0)
		{
			scanf("%d%d%d",&x,&v,&d);
			int now=B[x],L=D[x]-d,R=D[x]+d;
			if (x==1) 
			{
				Add_r(1,v);Add_r(d+1,-v);
				Ans1+=v;continue;
			}
			if (L<=0) Ans1+=v;
			if (L>0) Add(Fir[now]+max(L-1,0),v),Add(min(Fir[now]+R,Fir[now+1]),-v);
			if (L<=0) 
			{
				L=-L;
				Add_r(1,v);Add_r(L+1,-v);
				if (Fir[now]+L<Fir[now+1])
					Add(Fir[now]+L,v),Add(min(Fir[now]+R,Fir[now+1]),-v);
			}
		} else
		{
			scanf("%d",&x);
			if (x==1) printf("%d\n",Ans1);
				else 
				{
					printf("%d\n",Sum_r(D[x])+Sum(Fir[B[x]]+D[x]-1));
				}
		}
	}
}