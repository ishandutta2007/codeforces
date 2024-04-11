// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char ans[4][110];
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	if ( n==1 ) puts("a\na\nb\nb\n");
	else if ( n==2 ) puts("aa\nbb\naa\nbb");
	else if ( n%2==1 ) {
		ans[0][0]=ans[1][0]='a';
		x=0; y=1;
		for ( i=1; i<n; i+=2 ) {
			ans[0][i]=ans[0][i+1]='b'+x;
			ans[1][i]=ans[1][i+1]='b'+y;
			swap(x,y);
		}
		x=0; y=1;
		for ( i=0; i<n-1; i+=2 ) {
			ans[2][i]=ans[2][i+1]='d'+x;
			ans[3][i]=ans[3][i+1]='d'+y;
			swap(x,y);
		}
		ans[2][n-1]=ans[3][n-1]='f';
		for ( i=0; i<4; i++ ) puts(ans[i]);
	} else {
		x=0; y=1;
		for ( i=0; i<n; i+=2 ) {
			ans[0][i]=ans[0][i+1]='a'+x;
			ans[3][i]=ans[3][i+1]='g'+x;
			swap(x,y);
		}
		ans[1][0]=ans[2][0]='c';
		ans[1][n-1]=ans[2][n-1]='f';
		x=0; y=1;
		for ( i=1; i<n-1; i+=2 ) {
			ans[1][i]=ans[1][i+1]='d'+x;
			ans[2][i]=ans[2][i+1]='d'+y;
			swap(x,y);
		}
		for ( i=0; i<4; i++ ) puts(ans[i]);
	}
	return 0;
}