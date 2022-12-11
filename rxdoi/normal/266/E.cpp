#include<cstdio>
#include<cstring>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)
#define Rep(i) for (int i=0;i<=5;i++)
using namespace std;

const int Maxn=1e5+19,Mod=1e9+7;
typedef long long LL;
char s[5];
int n,m,Ql,Qr,k,cur,S[Maxn][6],A[Maxn],v;
int C[7][7]={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1}};
LL set[Maxn*4],sum[Maxn*4][6];

inline int Pow(int a,int b)
{
	LL res=1LL,tmp=a;
	for (;b;b>>=1,(tmp*=1LL*tmp)%=Mod) if (b&1) (res*=1LL*tmp)%=Mod;
	return res;
}
inline void Build(int x,int L,int R)
{
	if (L==R) {Rep(i) sum[x][i]=1LL*A[L]*Pow(L,i)%Mod;return;}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Rep(i) sum[x][i]=(sum[Lsn][i]+sum[Rsn][i])%Mod;
}
inline void Change(int x,int L,int R)
{
	Rep(i) sum[x][i]=1LL*set[x]*((S[R][i]-S[L-1][i]+Mod)%Mod)%Mod;
}
inline void Push_down(int x,int L,int R)
{
	if (set[x]==-1||L==R) return;
	set[Lsn]=set[Rsn]=set[x];
	Change(Lsn,L,Mid);Change(Rsn,Mid+1,R);
	set[x]=-1;
}
inline void Update(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) {set[x]=v;Change(x,L,R);return;}
	Push_down(x,L,R);
	if (Ql<=Mid) Update(Lsn,L,Mid);
	if (Qr>Mid) Update(Rsn,Mid+1,R);
	Rep(i) sum[x][i]=(sum[Lsn][i]+sum[Rsn][i])%Mod;
}
inline LL Query(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) return sum[x][cur];
	Push_down(x,L,R);
	LL tmp=0;
	if (Ql<=Mid) (tmp+=Query(Lsn,L,Mid))%=Mod;
	if (Qr>Mid) (tmp+=Query(Rsn,Mid+1,R))%=Mod;
	return tmp;
}

int main()
{
	memset(set,-1,sizeof(set));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]);
	for (int x=0;x<=5;x++)
		for (int i=1;i<=n;i++) S[i][x]=(S[i-1][x]+Pow(i,x))%Mod;
	Build(1,1,n);
	while (m--)
	{
		scanf("%s%d%d",s,&Ql,&Qr);
		if (s[0]=='=') scanf("%d",&v),Update(1,1,n);
		if (s[0]=='?') 
		{
			scanf("%d",&k);
			LL Ans=0;
			for (int i=0;i<=k;i++) cur=k-i,(Ans+=1LL*C[k][i]*Query(1,1,n)%Mod*Pow(-Ql+1,i)%Mod)%=Mod;
			printf("%I64d\n",(Ans+Mod)%Mod);
		}
	}
}