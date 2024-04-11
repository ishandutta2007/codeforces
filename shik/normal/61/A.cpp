// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char a[110],b[110];
	scanf("%s %s",a,b);
	for ( int i=0; a[i]; i++ ) putchar(a[i]==b[i]?'0':'1');
	return 0;
}