#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
char s[10];
int A[Maxn][Maxn],H[Maxn],L[Maxn];
int n,m,k,x,y;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=1;i<=n;i++) H[i]=i;
	for (int i=1;i<=m;i++) L[i]=i;
	while (k--)
	{
		scanf("%s%d%d",s,&x,&y);
		if (s[0]=='g') printf("%d\n",A[H[x]][L[y]]);
			else if (s[0]=='c') swap(L[x],L[y]);else swap(H[x],H[y]);
	}
}