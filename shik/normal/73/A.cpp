// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int x,y,z,k,a=1,b=1,c=1;
	scanf("%d%d%d%d",&x,&y,&z,&k);
	if ( k>x+y+z ) k=x+y+z;
	while ( k-- ) {
		if ( a<x && (a<=b||b==y) && (a<=c||c==z) ) a++;
		else if ( b<y && (b<=a||a==x) && (b<=c||c==z) ) b++;
		else if ( c<z && (c<=a||a==x) && (c<=b||b==y) ) c++;
	}
	printf("%I64d\n",1LL*a*b*c);
	return 0;
}