#include<cstdio>
#include<algorithm>
#define ERROR {printf("%d\n",Ans);continue;}
using namespace std;

const int Maxn=2e5+19,MAX=30;
int A[Maxn],To[Maxn][MAX+5],n;
long long Y[Maxn][MAX+5];

int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++) scanf("%d",&A[i]);
	for (int i=2;i<=n;i++)
	{
		int x=i,y=0;
		y+=A[x];x+=A[x];
		if (x<=1||x>n)
		{
			To[i][0]=(x==1?1:-1);
			Y[i][0]=y;continue;
		}
		y+=A[x];x-=A[x];
		if (x<=1||x>n)
		{
			To[i][0]=(x==1?1:-1);
			Y[i][0]=y;continue;
		}
		To[i][0]=x;
		Y[i][0]=y;
	}
	for (int i=1;i<=MAX;i++)
		for (int j=2;j<=n;j++)
		{
			int at=To[j][i-1];
			if (at==1||at==-1)
			{
				To[j][i]=at;
				Y[j][i]=Y[j][i-1];
			} else To[j][i]=To[at][i-1],Y[j][i]=Y[at][i-1]+Y[j][i-1];
		}
	for (int i=1;i<=n-1;i++)
	{
		int x=1+i;
		long long Ans=i;
		if (x<=0||x>n) ERROR;
		Ans+=A[x];x-=A[x];
		if (x<=0||x>n) ERROR;
		if (x==1) {printf("-1\n");continue;}
		if (To[x][MAX]>=1&&To[x][MAX]<=n) {printf("-1\n");continue;}
		printf("%I64d\n",Ans+Y[x][MAX]);
	}
}