#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 1000000007
using namespace std;

int n,m,i,j,k;
char s[3005][3005];
long long f[3005][3005];

long long dp(int Sx,int Sy,int Tx,int Ty)
{
	memset(f,0,sizeof(f));
	f[Sx][Sy]=1;
	for(i=Sx;i<=Tx;++i)
	{
		for(j=Sy;j<=Ty;++j)if(s[i][j]=='#')f[i][j]=0;
		for(j=Sy;j<Ty;++j)if(s[i][j+1]!='#')f[i][j+1]=(f[i][j+1]+f[i][j])%p;
		for(j=Sy;j<=Ty;++j)f[i+1][j]=f[i][j];
	}
	return f[Tx][Ty];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	printf("%I64d\n",(dp(1,2,n-1,m)*dp(2,1,n,m-1)%p+p-dp(1,2,n,m-1)*dp(2,1,n-1,m)%p)%p);
}