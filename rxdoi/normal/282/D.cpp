#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=300+9;
int F[Maxn][Maxn],n,Ans,A[3];

inline int DFS(int a,int b)
{
	a=max(a,0);b=max(b,0);
	if (!a&&!b) return 0;
	if (F[a][b]!=-1) return F[a][b];
	for (int i=1;i<=a;i++) if (DFS(a-i,b)==0) return F[a][b]=1;
	for (int i=1;i<=b;i++) if (DFS(a,b-i)==0) return F[a][b]=1;
	for (int i=1;i<=min(a,b);i++)
		if (DFS(a-i,b-i)==0) return F[a][b]=1;
	return F[a][b]=0;
}

int main()
{
	memset(F,-1,sizeof(F));
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	if (n==2) Ans=DFS(A[0],A[1]);else Ans=A[0]^A[1]^A[2];
	printf("%s\n",Ans?"BitLGM":"BitAryo");
}