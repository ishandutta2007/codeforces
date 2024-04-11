// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,p,q,g;
	scanf("%d%d",&a,&b);
	c=max(a,b);
	p=6-c+1;
	q=6;
	g=__gcd(p,q);
	printf("%d/%d\n",p/g,q/g);
	return 0;
}