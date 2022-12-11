#include<cstdio>
using namespace std;

const int Maxn=100+19;
int A[Maxn],c,n,Ans=0;

inline int max(int a,int b) {return a>b?a:b;}

int main()
{
	scanf("%d%d",&n,&c);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	for (int i=0;i<n-1;i++) Ans=max(Ans,A[i]-A[i+1]-c);
	printf("%d\n",Ans);
	return 0;
}