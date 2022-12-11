#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=300+19,oo=(1<<30)-1;
int F[2][Maxn][Maxn];
int A[Maxn][Maxn],n,cur,nxt;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%d",&A[i][j]);
	memset(F,128,sizeof(F));
	F[0][1][1]=A[1][1];
	cur=1;nxt=0;
	for (int s=0;s<n+n-2;s++)
	{
		cur^=1;nxt^=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) F[nxt][i][j]=-oo;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				for (int dx=0;dx<=1;dx++)
					for (int dy=0;dy<=1;dy++)
					{
						if (i+dx<1||i+dx>n||s+2-i+(dx^1)<1||s+2-i+(dx^1)>n) continue;
						if (j+dy<1||j+dy>n||s+2-j+(dy^1)<1||s+2-j+(dy^1)>n) continue;
						int tmp=A[i+dx][s+2-i+(dx^1)];
						if (i+dx!=j+dy) tmp+=A[j+dy][s+2-j+(dy^1)];
						F[nxt][i+dx][j+dy]=max(F[nxt][i+dx][j+dy],F[cur][i][j]+tmp);
					}
			}
	}
	printf("%d\n",F[nxt][n][n]);
}