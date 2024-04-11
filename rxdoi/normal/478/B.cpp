#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
int n,m;

LL F(int x) {return 1LL*x*(x-1)/2;}

int main()
{
	scanf("%d%d",&n,&m);
	printf("%I64d %I64d\n",1LL*(n%m)*F(n/m+1)+1LL*(m-n%m)*F(n/m),F(n-m+1));
}