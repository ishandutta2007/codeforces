#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=300+19;
int n,m,k,L,R,c;
long long C[N][N],f[N][N];

int main()
{
	n=IN(),m=IN(),k=IN();
	For(i,0,n+1) For(j,0,n+1) C[i][j]=1LL<<60;
	For(i,0,n+1) For(j,0,k+1) f[i][j]=1LL<<60;
	while (m--)
	{
		L=IN(),R=IN(),c=IN();
		For(i,L,R+1) For(j,i,R+1) C[i][j]=min(C[i][j],1LL*c);
	}
	f[0][0]=0;
	For(i,1,n+1) For(j,0,i+1)
	{
		f[i][j]=f[i-1][j];
		For(k,1,j+1) f[i][j]=min(f[i][j],f[i-k][j-k]+C[i-k+1][i]);
	}
	printf("%I64d\n",f[n][k]>=(1LL<<60)?-1:f[n][k]);
}