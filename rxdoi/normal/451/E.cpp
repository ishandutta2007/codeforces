#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=21,P=1e9+7;
typedef long long LL;
int Inv[N],n,Ans;
LL A[N],S;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}
int C(LL n,int m)
{
	if (n<m) return 0;
	int Ans=1;
	for (LL i=n-m+1;i<=n;i++) Ans=1LL*Ans*(i%P)%P;
	for (int i=1;i<=m;i++) Ans=1LL*Ans*Inv[i]%P;
	return Ans;
}

int main()
{
	scanf("%d%I64d",&n,&S);
	For(i,0,n) scanf("%I64d",&A[i]);
	For(i,1,n+1) Inv[i]=Pow(i,P-2)%P;
	For(i,0,1<<n)
	{
		int f=1;LL Sum=0;
		For(j,0,n) if (i>>j&1) f=-f,Sum+=A[j]+1;
		Ans+=f*C((S-Sum)+n-1,n-1);
		Ans=(Ans%P+P)%P;
	}
	printf("%d\n",Ans);
}