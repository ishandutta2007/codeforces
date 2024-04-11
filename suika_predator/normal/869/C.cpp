#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int a,b,c;
const int MOD=998244353;
int C[5010][5010];
long long fact[5010];
inline int sol(int n,int m)
{
	if(n>m)swap(n,m);//n<m
	int ret=0;
	for(int i=0;i<=n;i++)
	{
		long long tmp=1;
		tmp=(long long)C[n][i]*C[m][i];
		tmp%=MOD;
		tmp*=fact[i];
		tmp%=MOD;
		ret+=tmp;
		ret%=MOD;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	C[0][0]=1;
	for(int i=1;i<=5005;i++)
	{
		for(int j=0;j<=i;j++)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=MOD;
		}
	}
	fact[0]=1;
	for(int i=1;i<=5005;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	long long ans=1;
	ans=(ans*sol(a,b))%MOD;
	ans=(ans*sol(a,c))%MOD;
	ans=(ans*sol(b,c))%MOD;
	printf("%I64d\n",ans);
	return 0;
}