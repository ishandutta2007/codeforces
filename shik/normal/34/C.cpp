// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[100000],*p;
	int x,app[1010]={};
	gets(s);
	for ( p=strtok(s,","); p; p=strtok(0,",") ) {
		sscanf(p,"%d",&x);
		app[x]=1;
	}
	int flg=0;
	for ( int i=1,j; i<=1000; i=j ) {
		if ( !app[i] ) {
			j=i+1;
			continue;
		}
		if ( flg ) putchar(',');
		flg=1;
		if ( !app[i+1] ) {
			printf("%d",i);
			j=i+2;
			continue;
		}
		for ( j=i; app[j]; j++ );
		printf("%d-%d",i,j-1);
	}
	puts("");
	return 0;
}