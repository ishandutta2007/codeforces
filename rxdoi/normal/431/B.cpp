#include<cstdio>
using namespace std;

const int Maxn=10;
int s[Maxn][Maxn],Ans,A[Maxn],vis[Maxn];

void check()
{
	int tmp=0;
	tmp+=s[A[1]][A[2]]+s[A[2]][A[1]]+s[A[3]][A[4]]+s[A[4]][A[3]];
	tmp+=s[A[2]][A[3]]+s[A[3]][A[2]]+s[A[4]][A[5]]+s[A[5]][A[4]];
	tmp+=s[A[3]][A[4]]+s[A[4]][A[3]];
	tmp+=s[A[4]][A[5]]+s[A[5]][A[4]];
	if (tmp>Ans) Ans=tmp;
}

void DFS(int x)
{
	if (x==6) {check();return;}
	for (int i=1;i<=5;i++)
		if (!vis[i])
		{
			vis[i]=1;
			A[x]=i;
			DFS(x+1);
			vis[i]=0;
		}
}

int main()
{
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++) scanf("%d",&s[i][j]);
	DFS(1);
	printf("%d\n",Ans);
	return 0;
}