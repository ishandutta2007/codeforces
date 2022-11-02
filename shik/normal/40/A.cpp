// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char s[2][10]={"black","white"};
int main()
{
	int x,y,z;
	scanf("%d%d",&x,&y);
	z=(int)(sqrt(x*x+y*y)+1e-9);
	if ( z*z==x*x+y*y || x==0 || y==0 ) { puts("black"); return 0; }
	puts(s[(z%2)^(x*y<0)]);
	return 0;
}