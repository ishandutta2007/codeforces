// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cal_H( int n, char *s ) {
	int sh=0,st=0,a=0,b=0;
	for ( int i=0; i<n; i++ )
		if ( s[i]=='H' ) sh++;
		else st++;
	for ( int i=0; i<sh; i++ )
		if ( s[i]=='T' ) a++;
	for ( int i=sh; i<n; i++ )
		if ( s[i]=='H' ) b++;
	return max(a,b);
}
int cal_T( int n, char *s ) {
	int sh=0,st=0,a=0,b=0;
	for ( int i=0; i<n; i++ )
		if ( s[i]=='H' ) sh++;
		else st++;
	for ( int i=0; i<st; i++ )
		if ( s[i]=='H' ) a++;
	for ( int i=st; i<n; i++ )
		if ( s[i]=='T' ) b++;
	return max(a,b);
}
int main()
{
	int n,ans=514514514; char s[2010];
	scanf("%d %s",&n,s);
	for ( int i=0; i<n; i++ ) s[i+n]=s[i];
	for ( int i=0; i<n; i++ ) ans=min(ans,min(cal_H(n,s+i),cal_T(n,s+i)));
	printf("%d\n",ans);
	return 0;
}