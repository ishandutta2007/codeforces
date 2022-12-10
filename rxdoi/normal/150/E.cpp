#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=Last[x],y;~i;i=E[i].nxt) if (vis[y=E[i].y]!=Time)
#define mp make_pair
using namespace std;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long LL;
typedef double Db;
typedef pair<int,int> Pii;

const int N=1e5+19,oo=(1<<30)-1;
struct Edge {int y,z,nxt;} E[N*2];
int S[N],Last[N],vis[N];
int n,cnt,Time,L,R,Mid,Ql,Qr,x,y,z;
int cen,Fcen,Min,MaxL,Ansx,Ansy;
Pii A[N],B[N],MaxD;

struct Queue
{
	int Ql[N];Pii Qd[N];int L,R;
	void Clear() {R=-1,L=0;}
	void Ins(int Len,Pii Dis)
	{
		while (L<=R&&Dis>=Qd[R]) R--;
		R++,Ql[R]=Len,Qd[R]=Dis;
	}
	Pii Query(int Len)
	{
		while (L<=R&&Ql[L]>Len) L++;
		return L<=R?Qd[L]:mp(-oo,0);
	}
} Q;

void Link(int x,int y,int z)
{
	E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,z,Last[y]};Last[y]=cnt++;
}
void Findcen(int x,int Fa,int n)
{
	S[x]=1;int tmp=0;
	Rep(x) if (y!=Fa)
		Findcen(y,x,n),S[x]+=S[y],tmp=max(tmp,S[y]);
	tmp=max(tmp,n-S[x]);
	if (tmp<Min) Min=tmp,cen=x,Fcen=Fa;
}
void DFS(int x,int Fa,int Len,int Dis)
{
	A[Len]=max(A[Len],mp(Dis,x));
	Rep(x) if (y!=Fa) DFS(y,x,Len+1,Dis+(E[i].z>=Mid?1:-1));
}
int Solve(int x,int n)
{
	Min=oo,Findcen(x,-1,n),vis[x=cen]=Time;
	if (~Fcen) S[Fcen]=n-S[x];
	For(i,0,n) B[i]=mp(-oo,0);B[0]=mp(0,x);
	MaxL=Qr,MaxD=mp(-oo,0);
	Rep(x)
	{
		For(i,1,S[y]+1) A[i]=mp(-oo,0);
		DFS(y,x,1,E[i].z>=Mid?1:-1);
		Q.Clear();Q.Ins(MaxL,MaxD);
		For(i,1,S[y]+1)
		{
			if (0<=Ql-i&&Ql-i<n) Q.Ins(Ql-i,B[Ql-i]);
			if (A[i].first+Q.Query(Qr-i).first>=0)
				return Ansx=A[i].second,Ansy=Q.Query(Qr-i).second,1;
		}
		For(i,1,S[y]+1) if (A[i]>B[i])
		{
			B[i]=A[i];
			if (Ql<=i&&i<=Qr&&B[i]>MaxD) MaxD=B[i],MaxL=i;
		}
	}
	Rep(x) if (Solve(y,S[y])) return 1;
	return 0;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),Ql=IN(),Qr=IN();
	For(i,1,n) x=IN(),y=IN(),z=IN(),Link(x,y,z),R=max(R,z);
	while (L<=R)
	{
		Mid=(L+R)>>1;Time++;
		if (Solve(1,n)) L=Mid+1;else R=Mid-1;
	}
	printf("%d %d\n",Ansx,Ansy);
}