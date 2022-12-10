#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=24,Mod=1e9+7;
int f[1<<N],S[1<<N],Lg[1<<N],A[N],k[3],t,b,n;

int main()
{
	scanf("%d",&n);
	For(i,0,n) scanf("%d",&A[i]);
	scanf("%d",&k[0]);
	For(i,1,k[0]+1) scanf("%d",&k[i]);
	f[0]=1;For(i,0,n) Lg[1<<i]=i;
	For(i,1,1<<n)
	{
		S[i]=S[i^i&-i]+A[Lg[i&-i]];
		if (S[i]!=k[1]&&S[i]!=k[2])
			for (int j=Lg[t=i,t&-t];t;j=Lg[t^=1<<j,t&-t]) (f[i]+=f[i^1<<j])%=Mod;
	}
	printf("%d\n",f[(1<<n)-1]);
}