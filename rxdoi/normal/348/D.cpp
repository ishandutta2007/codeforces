#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=3000+19,Mod=1e9+7;
typedef long long LL;
LL F[Maxn][Maxn];
char s[Maxn][Maxn];
int n,m;

LL calc(int a,int b,int x,int y)
{
	if (s[a][b]=='#') return 0;
	memset(F,0,sizeof(F));
	F[1][1]=1;
	for (int i=a;i<=x;i++)
		for (int j=b;j<=y;j++) 
			if (s[i][j]=='.') (F[i][j]+=F[i][j-1]+F[i-1][j])%=Mod;
	return F[x][y];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	LL Ans=calc(2,1,n,m-1)*calc(1,2,n-1,m)%Mod;
	Ans=(Ans-calc(1,2,n,m-1)*calc(2,1,n-1,m)%Mod+Mod)%Mod;
	printf("%I64d\n",Ans);
}