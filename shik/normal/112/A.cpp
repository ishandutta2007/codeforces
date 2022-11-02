// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
	char a[200],b[200];
	scanf("%s %s",a,b);
	for ( int i=0; a[i]; i++ )
	   if ( tolower(a[i])!=tolower(b[i]) ) {
		   printf("%d\n",tolower(a[i])<tolower(b[i])?-1:1);	
		   return 0;
	   }
	puts("0");
	return 0;
}

//XD