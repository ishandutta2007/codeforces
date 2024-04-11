#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=Last[x];~i;i=E[i].nxt) if (!vis[E[i].y])
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19,oo=(1<<30)-1,P=950009857,Mod=233333;
struct Edge {int y,nxt;} E[N*2];
typedef int one[N];
one f,g,A,Last,S,vis,k1,k2,D,Pk,Ik,V;
int n,Q,K,C,cnt,cen,Fcen,Min,tot;
long long Ans;

struct Hashset
{
	int A[Mod*2],key[Mod*2],Last[Mod],nxt[Mod*2],T[Mod*2],cnt,Time;

	Hashset() {memset(nxt,-1,sizeof(nxt));}
	void Clear() {Time++;cnt=Mod;}
	void New(int x) {T[x]=Time,key[x]=1,nxt[x]=-1;}
	void I(int x)
	{
		int t=x%Mod;
		for (int i=x%Mod;~i&&T[i]==Time;i=nxt[i]) if (A[i]==x) {key[i]++;return;}
		if (T[t]!=Time) New(t),A[t]=x,Last[t]=t;
			else New(cnt),A[cnt]=x,nxt[Last[t]]=cnt,Last[t]=cnt++;
	}
	int Q(int x)
	{
		for (int i=x%Mod;~i&&T[i]==Time;i=nxt[i]) if (A[i]==x) return key[i];
		return 0;
	}
} M1,M2;

int Pow(int a,int b,int P)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}
void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}

void Find_cen(int x,int Fa)
{
	S[x]=1;int res=0;
	Rep(x) if (E[i].y!=Fa)
		Find_cen(E[i].y,x),S[x]+=S[E[i].y],res=max(res,S[E[i].y]);
	res=max(res,n-S[x]);
	if (res<Min) Min=res,cen=x,Fcen=Fa;
}
void DFS(int x,int Fa,int Dis,int key1,int key2)
{
	D[x]=Dis,k1[x]=key1,k2[x]=key2,V[tot++]=x;
	M1.I(1LL*(C-key2+Q)*Ik[Dis+1]%Q);
	M2.I(key1);
	Rep(x) if (E[i].y!=Fa)
		DFS(E[i].y,x,Dis+1,(key1+1LL*Pk[Dis]*A[E[i].y])%Q,(1LL*key2*K+A[E[i].y])%Q);
}
void Calc(int s)
{
	For(i,0,tot)
	{
		int x=V[i];
		f[x]+=s*M1.Q(k1[x]);
		g[x]+=s*M2.Q(1LL*(C-k2[x]+Q)*Ik[D[x]+1]%Q);
	}
}
void Solve(int x,int n)
{
	Min=oo,Find_cen(x,-1);vis[x=cen]=1;
	if (~Fcen) S[Fcen]=n-S[x];
	M1.Clear(),M2.Clear(),tot=0;
	DFS(x,-1,0,0,A[x]),Calc(1);
	Rep(x)
		M1.Clear(),M2.Clear(),tot=0,
		DFS(E[i].y,-1,1,k1[E[i].y],k2[E[i].y]),Calc(-1);
	Rep(x) Solve(E[i].y,S[E[i].y]);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),Q=IN(),K=IN(),C=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n) Link(IN(),IN());
	Pk[0]=1;For(i,1,n+1) Pk[i]=1LL*Pk[i-1]*K%Q;
	For(i,1,n+1) Ik[i]=Pow(Pk[i],Q-2,Q);

	Solve(1,n);

	For(i,1,n+1)
	{
		int f0=n-f[i],f1=f[i],g0=n-g[i],g1=g[i];
		Ans+=1LL*f0*g1+1LL*f1*g0;
		Ans+=2LL*f0*f1;
		Ans+=2LL*g0*g1;
	}
	printf("%I64d\n",1LL*n*n*n-Ans/2);
}