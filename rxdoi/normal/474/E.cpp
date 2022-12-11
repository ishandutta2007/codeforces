#include<cstdio>
#include<algorithm>
#define mp make_pair
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int Maxn=1e5+19;
int pre[Maxn],out[Maxn],cnt,n,d;
LL A[Maxn],B[Maxn];
PII F[Maxn],G[Maxn],Ans;

inline void F_Update(int x,PII v) {while (x<=n) F[x]=max(F[x],v),x+=x&-x;}
inline void G_Update(int x,PII v) {while (x<=n) G[x]=max(G[x],v),x+=x&-x;}
inline PII F_Query(int x) 
{
	PII Ans=mp(0,0);while (x) Ans=max(Ans,F[x]),x-=x&-x;return Ans;
}
inline PII G_Query(int x) 
{
	PII Ans=mp(0,0);while (x) Ans=max(Ans,G[x]),x-=x&-x;return Ans;
}

int main()
{
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);
	Ans=mp(0,0);
	for (int i=1;i<=n;i++)
	{
		int sm=lower_bound(B+1,B+n+1,A[i]-d+1)-B-1;
		int bg=lower_bound(B+1,B+n+1,A[i]+d)-B;
		PII _F=(sm==0?mp(0,0):F_Query(sm));
		PII _G=(bg==n+1?mp(0,0):G_Query(n-bg+1));
		PII tmp;
		if (_F>_G) tmp=_F,pre[i]=_F.second;else tmp=_G,pre[i]=_G.second;
		tmp.first++;tmp.second=i;
		int x=lower_bound(B+1,B+n+1,A[i])-B;
		F_Update(x,tmp);
		G_Update(n-x+1,tmp);
		if (tmp>Ans) Ans=tmp;
	}
	printf("%d\n",Ans.first);
	for (int i=Ans.second;i!=0;i=pre[i]) out[cnt++]=i;
	for (int i=cnt-1;i>=0;i--) printf("%d ",out[i]);puts("");
}