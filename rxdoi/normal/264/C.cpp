#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
const LL oo=1LL<<60;
struct note {LL Ans,col;} Max1,Max2;
int n,Q,a,b;
int c[Maxn],v[Maxn];
LL F[Maxn];

inline LL Get_Max(int V,int C)
{
	LL tmp1=max(1LL*b*V,F[C]+1LL*a*V);
	LL tmp2;
	if (Max1.col!=C) tmp2=Max1.Ans+1LL*b*V;else tmp2=Max2.Ans+1LL*b*V;
	return max(tmp1,tmp2);
}

int main()
{
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	while (Q--)
	{
		scanf("%d%d",&a,&b);
		Max1=(note){-oo,-1};
		Max2=(note){-oo,-1};
		for (int i=1;i<=n;i++) F[i]=-oo;
		for (int i=1;i<=n;i++)
		{
			F[c[i]]=max(F[c[i]],Get_Max(v[i],c[i]));
			if (F[c[i]]>Max1.Ans) 
			{
				if (c[i]!=Max1.col) Max2=Max1;
				Max1=(note){F[c[i]],c[i]};
			} else
			if (F[c[i]]>Max2.Ans&&c[i]!=Max1.col) Max2=(note){F[c[i]],c[i]};
		}
		printf("%I64d\n",max(0LL,Max1.Ans));
	}
}