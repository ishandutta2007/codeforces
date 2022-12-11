#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n<=m/2) return printf("%d\n",n),0;
	if (n<m)
	{
		int Ans=0;
		while (n>=1&&m>=2&&n<m) Ans++,m-=2,n--;
		printf("%d\n",n/3*2+(n%3==2)+Ans);
		return 0;
	}
	if (n==m) return printf("%d\n",n/3*2+(n%3==2)),0;
}