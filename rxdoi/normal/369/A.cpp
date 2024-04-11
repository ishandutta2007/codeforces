#include<cstdio>
using namespace std;

int n,a,b,x,Ans;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x==1) (a?a--:Ans++);
		if (x==2) (b?b--:(a?a--:Ans++));
	}
	printf("%d\n",Ans);
}