#include<cstdio>
#include<vector>
#include<algorithm>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
vector<int> in[Maxn],out[Maxn];
int n,k,L,R,Ql,Qr;
int A[Maxn],Re[Maxn*4],Sum[Maxn*4],tot[Maxn*4];
LL Ans;

inline void Change(int x) {Re[x]^=1;Sum[x]=tot[x]-Sum[x];}
inline void Push_down(int x)
{
	if (!Re[x]||tot[x]==1) return;Re[x]=0;
	Change(Lsn),Change(Rsn);
}
inline void Reserve(int x,int L,int R)
{
	Push_down(x);
	if (Ql<=L&&R<=Qr) {Change(x);return;}
	int Mid=(L+R)>>1;
	if (Ql<=Mid) Reserve(Lsn,L,Mid);
	if (Qr>Mid) Reserve(Rsn,Mid+1,R);
	Sum[x]=Sum[Lsn]+Sum[Rsn];
}
inline void Build(int x,int L,int R)
{
	if (L==R) {tot[x]=1;return;}
	int Mid=(L+R)>>1;
	Build(Lsn,L,Mid);Build(Rsn,Mid+1,R);
	tot[x]=tot[Lsn]+tot[Rsn];
}
inline int Query(int x,int L,int R)
{
	Push_down(x);
	if (Ql<=L&&R<=Qr) return Sum[x];
	int Mid=(L+R)>>1,Ans=0;
	if (Ql<=Mid) Ans+=Query(Lsn,L,Mid);
	if (Qr>Mid) Ans+=Query(Rsn,Mid+1,R);
	return Ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	for (int i=0;i<k;i++) 
	{
		scanf("%d%d",&L,&R);
		int LL=lower_bound(A+1,A+n+1,L)-A;
		int RR=upper_bound(A+1,A+n+1,R)-A-1;
		if (LL>=1&&LL<=n&&RR>=1&&RR<=n)
			in[LL].push_back(RR),out[RR].push_back(LL);
	}
	Ans=1LL*n*(n-1)*(n-2)/6LL;
	Build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<in[i].size();j++) 
		{
			Ql=i,Qr=in[i][j];
			Reserve(1,1,n);
		}
		int tmp=0;
		if (i>1) Ql=1,Qr=i-1,tmp+=i-1-Query(1,1,n);
		if (i<n) Ql=i+1,Qr=n,tmp+=Query(1,1,n);
		Ans-=1LL*tmp*(tmp-1)/2LL;
		for (int j=0;j<out[i].size();j++) Ql=out[i][j],Qr=i,Reserve(1,1,n);
	}
	printf("%I64d\n",Ans);
}