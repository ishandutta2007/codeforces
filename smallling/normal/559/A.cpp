#include<cstdio>
#include<algorithm>

using namespace std;

int a,b,c,d,e,f;

int main()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("%d\n",(a+b+c)*(a+b+c)-a*a-c*c-e*e);
}