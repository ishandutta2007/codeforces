#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a,b;

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if (a*m<=b) printf("%d\n",n*a);
		else printf("%d\n",min((n/m+(n%m!=0))*b,n/m*b+n%m*a));
}