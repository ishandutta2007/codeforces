#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn][Maxn],n,m;

int Matrixcmp(int Up,int Dn)
{
	for (int i=0;i<m;i++) 
		if (A[Up][i]!=A[Dn][i]) return 0;
	return 1;
}
int DFS(int n)
{
	if (n&1) return n;
	int Half=(n>>1);
	for (int i=0;i<Half;i++)
		if (!Matrixcmp(i,n-i-1)) return n;
	return DFS(n>>1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) scanf("%d",&A[i][j]);
	printf("%d\n",DFS(n));
	return 0;
}