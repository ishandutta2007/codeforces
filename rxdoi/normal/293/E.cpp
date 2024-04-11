#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(x) for (int i=Last[x];~i;i=E[i].nxt) if (!vis[E[i].y])
using namespace std;

const int N=1e5+19;
struct Edge {int y,z,nxt;} E[N*2];
struct node
{
	int v,d;
	bool operator < (const node& B) const {return v<B.v;}
} A[N];
int Last[N],S[N],vis[N],C[N];
int n,l,w,x,z,cnt,Min,Cen,Fcen,tot;
long long Ans;

int Query(int x) {int Ans=0;for (;x;x-=x&-x) Ans+=C[x];return Ans;}
void Update(int x,int v) {for (;x<=l+1;x+=x&-x) C[x]+=v;}
void Link(int x,int y,int z)
{
	E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,z,Last[y]};Last[y]=cnt++;
}

void Find_cen(int x,int Fa,int n)
{
	S[x]=1;int res=0;
	For(x) if (E[i].y!=Fa)
		Find_cen(E[i].y,x,n),S[x]+=S[E[i].y],res=max(res,S[E[i].y]);
	res=max(res,n-S[x]);
	if (res<Min) Min=res,Cen=x,Fcen=Fa;
}
void DFS(int x,int Fa,int v,int d)
{
	A[tot].v=v,A[tot].d=d;tot++;
	For(x) if (E[i].y!=Fa) DFS(E[i].y,x,v+E[i].z,d+1);
}
long long Calc(int x,int v,int d)
{
	tot=0;DFS(x,-1,v,d);sort(A,A+tot);
	long long Ans=0;
	for (int i=0;i<tot;i++) Update(A[i].d+1,1);
	for (int L=0,R=tot-1;L<=R;L++)
	{
		Update(A[L].d+1,-1);
		while (L<R&&A[L].v+A[R].v>w) Update(A[R].d+1,-1),R--;
		if (A[L].d<=l) Ans+=Query(l-A[L].d+1);
	}
	return Ans;
}
void Solve(int x,int n)
{
	Min=(1<<30)-1,Find_cen(x,-1,n),vis[x=Cen]=1;
	Ans+=Calc(x,0,0);
	For(x) Ans-=Calc(E[i].y,E[i].z,1);
	For(x) Solve(E[i].y,E[i].y==Fcen?n-S[x]:S[E[i].y]);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d%d",&n,&l,&w);
	for (int i=2;i<=n;i++) scanf("%d%d",&x,&z),Link(i,x,z);
	Solve(1,n);
	printf("%I64d\n",Ans);
}