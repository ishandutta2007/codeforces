#include<cstdio>
using namespace std;

const int Maxn=2*100000+19;
int A[Maxn],Ans,n,t,c;

int main()
{
	scanf("%d%d%d",&n,&t,&c);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]=A[i-1]+(A[i]>t);
	for (int i=c;i<=n;i++) Ans+=(A[i]==A[i-c]);
	printf("%d\n",Ans);
	return 0;
}