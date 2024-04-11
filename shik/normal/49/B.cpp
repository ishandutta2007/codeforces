// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int get( char *a, char *b, int t ) {
	int x=0,y=0,z,r=0;
	for ( int i=0; a[i]; i++ ) x=x*t+a[i]-'0';
	for ( int i=0; b[i]; i++ ) y=y*t+b[i]-'0';
	for ( z=x+y; z; z/=t ) r++;
	return r;
}
int main()
{
	char a[10],b[10];
	scanf("%s %s",a,b);
	int t=max(*max_element(a,a+strlen(a)),*max_element(b,b+strlen(b)))-'0'+1,ans=0;
	for ( int i=t; i<=1000; i++ ) ans=max(ans,get(a,b,i));
	printf("%d\n",ans);
	return 0;
}