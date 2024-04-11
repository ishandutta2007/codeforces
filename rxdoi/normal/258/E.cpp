#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (((L)+(R))>>1)
using namespace std;

const int Maxn=1e5+19;
struct Edge {int y,nxt;} E[Maxn*2];
struct Updates 
{
	int x,L,R,v;
	bool operator < (const Updates &B) const {return x<B.x;}
} A[Maxn*8];
int Last[Maxn],Ecnt;
int n,Q,x,y,tot,Utot,now,v,z,Ans[Maxn];
int in[Maxn],out[Maxn],Dis[Maxn];
int cnt[Maxn*4],add[Maxn*4],Ql,Qr;

inline void Link(int x,int y)
{
	E[Ecnt]=(Edge){y,Last[x]};Last[x]=Ecnt++;
	E[Ecnt]=(Edge){x,Last[y]};Last[y]=Ecnt++;
}
inline void DFS(int x,int Fa)
{
	tot++;Dis[tot]=x;in[x]=tot;
	for (int i=Last[x];i!=-1;i=E[i].nxt) if (E[i].y!=Fa) DFS(E[i].y,x);
	out[x]=tot;
}
inline void Change(int x,int L,int R) 
{
	if (add[x]) cnt[x]=R-L+1;else cnt[x]=(L==R?0:cnt[Lsn]+cnt[Rsn]);
}
inline void Update(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) {add[x]+=v;Change(x,L,R);return;}
	if (Ql<=Mid) Update(Lsn,L,Mid);
	if (Qr>Mid) Update(Rsn,Mid+1,R);
	Change(x,L,R);
}
inline void Add_Update(int a,int b,int L,int R)
{
	A[Utot++]=(Updates){a,L,R,1};
	A[Utot++]=(Updates){b+1,L,R,-1};
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&Q);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Link(x,y);
	DFS(1,0);
	while (Q--)
	{
		scanf("%d%d",&x,&y);
		Add_Update(in[x],out[x],in[x],out[x]);
		Add_Update(in[x],out[x],in[y],out[y]);
		Add_Update(in[y],out[y],in[x],out[x]);
		Add_Update(in[y],out[y],in[y],out[y]);
	}
	sort(A,A+Utot);
	for (int i=1;i<=tot;i++)
	{
		while (z<Utot&&A[z].x==i) Ql=A[z].L,Qr=A[z].R,v=A[z].v,Update(1,1,tot),z++;;
		Ans[Dis[i]]=max(cnt[1]-1,0);
	}
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);puts("");
}