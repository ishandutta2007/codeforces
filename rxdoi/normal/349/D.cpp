#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
struct son {int y,nxt;} s[Maxn];
struct Edge {int y,nxt;} E[Maxn<<1];
int sL[Maxn],EL[Maxn],Fa[Maxn];
LL A[Maxn],D[Maxn],Ans;
int n,s_cnt,E_cnt,x,y;

inline LL gcd(LL a,LL b) {return !b?a:gcd(b,a%b);}
inline LL lcm(LL a,LL b) {return !b?a:a/gcd(a,b)*b;}
inline void E_Add(int x,int y) {E[E_cnt]=(Edge){y,EL[x]};EL[x]=E_cnt++;}
inline void s_Add(int x,int y) {s[s_cnt]=(son){y,sL[x]};sL[x]=s_cnt++;}
inline void DFS(int x)
{
	if (A[x]) {D[x]=1;return;}
	LL cnt=0,_lcm=1,_min=1LL<<60;
	for (int i=EL[x];i^-1;i=E[i].nxt)
		if (E[i].y^Fa[x]) 
		{
			Fa[E[i].y]=x;s_Add(x,E[i].y);
			DFS(E[i].y);
			cnt++;_lcm=lcm(_lcm,D[E[i].y]);_min=min(_min,A[E[i].y]);
		}
	D[x]=_lcm*cnt;
	for (int i=sL[x];i^-1;i=s[i].nxt) Ans+=A[s[i].y]-(_min/_lcm*_lcm);
	A[x]=(_min/_lcm*_lcm)*cnt;
}

int main()
{
	memset(sL,-1,sizeof(sL));
	memset(EL,-1,sizeof(EL));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),E_Add(x,y),E_Add(y,x);
	DFS(1);
	printf("%I64d\n",Ans);
}