// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
bool chk( int x ) { return x>=1000 && x<=2011; }
int main()
{	
	int n,num[N]={},i,j,k,now;
	char s[10],t[10];
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d",num+i);
	for ( i=1; i<=n; i++ ) {
		sprintf(s,"%d",num[i]);
		for ( j=0; j<4; j++ ) {
			for ( k=0; k<10; k++ ) {
				strcpy(t,s);
				t[j]=k+'0';
				sscanf(t,"%d",&now);
				if ( chk(now) && now>=num[i-1] && (now<num[i] || !chk(num[i]) || num[i]<num[i-1] ) ) num[i]=now;
			}
		}
		if ( !chk(num[i]) || num[i]<num[i-1] ) {
			puts("No solution");
			return 0;
		} 
	}
	for ( i=1; i<=n; i++ ) printf("%d\n",num[i]);
	return 0;
}