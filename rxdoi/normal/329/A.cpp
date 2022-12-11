#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn][Maxn],Ans[Maxn],Ans2[Maxn],n,H=1,L=1;
char s[Maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=n;j++) A[i][j]=(s[j-1]=='.');
	}
	for (int i=1;i<=n;i++)
	{
		int Flag=1;
		for (int j=1;j<=n;j++) 
			if (A[i][j]) Flag=0,Ans[i]=j;
		if (Flag) {H=0;break;}
	}
	for (int i=1;i<=n;i++)
	{
		int Flag=1;
		for (int j=1;j<=n;j++) if (A[j][i]) Flag=0,Ans2[i]=j;
		if (Flag) {L=0;break;}
	}
	if (!H&&!L) printf("-1\n");
		else if (!L) for (int i=1;i<=n;i++) printf("%d %d\n",i,Ans[i]);
			else for (int i=1;i<=n;i++) printf("%d %d\n",Ans2[i],i);
		
}