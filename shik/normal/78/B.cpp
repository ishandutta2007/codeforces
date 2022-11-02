// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char clr[]="ROYGBIV";
int n,sol[110];
bool chk() {
	int app[7]={};
	for ( int i=0; i<4; i++ ) sol[n+i]=sol[i];
	for ( int i=0; i<n; i++ ) app[sol[i]]=1;
	for ( int i=0; i<7; i++ )
		if ( !app[i] ) return 0;
	for ( int i=0; i<n; i++ ) 
		if ( sol[i]==sol[i+1] || sol[i]==sol[i+2] || sol[i]==sol[i+3] ) return 0;
	return 1;
}
void gen() {
	for ( int i=0; i<n; i++ ) {
		sol[i]=rand()%7;
		for ( int j=1; j<=3&&i-j>=0; j++ )
			if ( sol[i]==sol[i-j] ) {
				i--;
				break;
			}
	}
}
int main()
{
	scanf("%d",&n);
	do { gen(); } while ( !chk() );
	for ( int i=0; i<n; i++ ) putchar(clr[sol[i]]);
	puts("");
	return 0;
}