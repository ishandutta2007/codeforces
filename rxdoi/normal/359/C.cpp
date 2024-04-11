#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19,Mod=1e9+7;
typedef long long LL;
vector<LL> S;
LL sum,A[Maxn],n,x,now;

inline LL Power(LL a,LL b)
{
	LL Res=1,tmp=a;
	while (b) {if (b&1) Res=Res*tmp%Mod;tmp=tmp*tmp%Mod;b>>=1;}
	return Res;
}

int main()
{
	scanf("%d%d",&n,&x);
	for (int i=0;i<n;i++) scanf("%I64d",&A[i]),sum+=A[i];
	for (int i=0;i<n;i++) S.push_back(sum-A[i]);
	while (1)
	{
		LL v=S[S.size()-1],cnt=0;
		while (S.size()&&S[S.size()-1]==v) cnt++,S.pop_back();
		if (cnt%x==0)
		{
			cnt/=x;
			for (int i=0;i<cnt;i++) S.push_back(v+1);
		}
		else {printf("%I64d\n",Power(x,min(1LL*v,sum)));return 0;}
	}
}