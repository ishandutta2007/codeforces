#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500000+19;
struct Edge {int y,nxt;} E[N*2];
int Last[N],In[N],Out[N];
int cnt,n,Q,opt,x,tot;

struct SegTree
{
	int Set[N*4],Max[N*4],Ql,Qr,Qv;
	SegTree()
	{
		memset(Set,-1,sizeof(Set));
		memset(Max,-1,sizeof(Max));
	}
	void Setset(int x,int v) {Set[x]=Max[x]=v;}
	void Down(int x,int L,int R)
	{
		if (Set[x]==-1||L==R) return;
		Setset(Lsn,Set[x]),Setset(Rsn,Set[x]);Set[x]=-1;
	}
	void Update(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) {Setset(x,Qv);return;}
		Down(x,L,R);
		if (Ql<=Mid) Update(Lsn,L,Mid);
		if (Qr>Mid) Update(Rsn,Mid+1,R);
		Max[x]=max(Max[Lsn],Max[Rsn]);
	}
	int Qmax(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) return Max[x];
		Down(x,L,R);
		int res=-1;
		if (Ql<=Mid) res=max(res,Qmax(Lsn,L,Mid));
		if (Qr>Mid) res=max(res,Qmax(Rsn,Mid+1,R));
		return res;
	}
	void Modify(int L,int R,int v) {Ql=L,Qr=R,Qv=v;Update(1,1,n);}
	int Query(int L,int R) {return Ql=L,Qr=R,Qmax(1,1,n);}
} S,T;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x,int Fa)
{
	In[x]=++tot;
	for (int i=Last[x];~i;i=E[i].nxt) if (E[i].y!=Fa) DFS(E[i].y,x);
	Out[x]=tot;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	memset(S.Max,0,sizeof(S.Max));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	DFS(1,-1);
	Q=IN();
	For(i,1,Q+1)
	{
		opt=IN(),x=IN();
		if (opt==1) T.Modify(In[x],Out[x],i);
		if (opt==2) S.Modify(In[x],In[x],i);
		if (opt==3) puts(S.Query(In[x],Out[x])>T.Query(In[x],In[x])?"0":"1");
	}
}