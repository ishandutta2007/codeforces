#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=5000+19,Mod=1e9+7;
int F[Maxn][Maxn],s[Maxn];
int n,a,b,k;

inline void Get_sum(int x)
{
	for (int i=1;i<=n;i++) s[i]=(s[i-1]+F[x][i])%Mod;
}

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	F[0][a]=1;
	Get_sum(0);
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (j==b) continue;
			int L,R;
			if (j<b) 
			{
				L=1,R=(j+b)/2;
				if (R-j==b-R) R--;
			} else
			{
				L=(j+b)/2+(j+b)%2;R=n;
				if (j-L==L-b) L++;
			}
			L=max(L,1),R=min(R,n);
			F[i][j]=((s[R]-s[L-1]+Mod)%Mod-F[i-1][j]+Mod)%Mod;
		}
		Get_sum(i);
	}
	printf("%d\n",s[n]);
}