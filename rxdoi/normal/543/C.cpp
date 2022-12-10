#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=29,oo=(1<<30)-1;
int f[1<<20],A[N][N],M[N][N],C[N][N],Lg[1<<20];
int n,m;
char s[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	For(i,0,n) Lg[1<<i]=i;
	For(i,0,n) scanf("%s",s[i]);
	For(i,0,n) For(j,0,m) scanf("%d",&A[i][j]);
	For(i,0,n) For(j,0,m)
	{
		int &m=M[i][j],&c=C[i][j],Max=0;
		For(k,0,n) if (s[i][j]==s[k][j]) m|=1<<k,c+=A[k][j],Max=max(Max,A[k][j]);
		c-=Max;
	}
	memset(f,64,sizeof(f));f[0]=0;
	For(i,0,m) For(t,0,(1<<n)-1)
		if (f[t]<oo) For(x,0,n)
			if (!(t>>x&1))
				f[t|1<<x]=min(f[t|1<<x],f[t]+A[x][i]),
				f[t|M[x][i]]=min(f[t|M[x][i]],f[t]+C[x][i]);
	printf("%d\n",f[(1<<n)-1]);
}