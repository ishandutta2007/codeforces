#include<set>
#include<cstdio>
using namespace std;

const int Maxn=100000+19,Bit=30;
int A[Maxn];
int n,m,x,v;
long long Ans;
set<int> S[Bit];

inline int is_1(int a,int Dis) {return (a>>Dis)&1;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=0;i<Bit;i++) 
		for (int j=0;j<=n+1;j++) 
		{
			int tmp=is_1(A[j],i);
			if (!is_1(A[j],i)) S[i].insert(j);
		}
	for (int i=0;i<Bit;i++)
		if (S[i].size()>1)
			for (set<int>::iterator j=++S[i].begin();j!=S[i].end();j++)
			{
				set<int>::iterator k=j;--k;
				Ans+=(1LL<<i)*(*j-*k-1)*(*j-*k)>>1;
			}
	while (m--)
	{
		scanf("%d%d",&x,&v);
		for (int j=0;j<Bit;j++)
		{
			set<int>::iterator L=--S[j].lower_bound(x);
			set<int>::iterator R=S[j].upper_bound(x);
			long long delta=(1LL*(*R-*L-1)*(*R-*L)>>1)
				-((1LL*(x-*L-1)*(x-*L)+1LL*(*R-x-1)*(*R-x))>>1);
			if (is_1(A[x],j)&&!is_1(v,j)) {Ans-=delta*(1LL<<j);S[j].insert(x);}
			if (!is_1(A[x],j)&&is_1(v,j)) {Ans+=delta*(1LL<<j);S[j].erase(x);}
		}
		A[x]=v;
		printf("%I64d\n",Ans);
	}
}