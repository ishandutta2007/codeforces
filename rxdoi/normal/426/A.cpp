#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int n,s,A[Maxn],Ans=0;

int main()
{
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	for (int i=0;i<n-1;i++) Ans+=A[i];
	printf("%s\n",Ans<=s?"YES":"NO");
	return 0;
}