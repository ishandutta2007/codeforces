#include<cstdio>
using namespace std;

int n,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) Ans+=i*(n-i)+1;
	printf("%d\n",Ans);
}