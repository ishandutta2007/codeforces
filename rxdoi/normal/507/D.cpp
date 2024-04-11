#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1000+19;
int f[N][100][2],Pp[N],Pk[N];
int n,k,P;

int F(int x,int t,int C)
{
	int &Ans=f[x][t][C];
	if (~Ans) return Ans;
	if (!t&&C) return Ans=(x==n?1:9LL*Pp[n-x-1]%P);
	if (x==n) return Ans=0;Ans=0;
	For(i,0,10) (Ans+=F(x+1,(t+1LL*i*Pk[x]%k)%k,C||i))%=P;
	return Ans;
}

int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&k,&P);
	Pp[0]=1;For(i,1,n+1) Pp[i]=10LL*Pp[i-1]%P;
	Pk[0]=1;For(i,1,n+1) Pk[i]=10LL*Pk[i-1]%k;
	printf("%d\n",F(0,0,0));
}