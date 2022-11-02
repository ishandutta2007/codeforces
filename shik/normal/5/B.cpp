// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
char s[N][N];
int len[N];
void print( int t, char c ) { while ( t-- ) putchar(c); }
int main()
{
	int n=0,L=0,flg=0;
	while ( gets(s[n]) ) n++;
	for ( int i=0; i<n; i++ ) len[i]=strlen(s[i]);
	L=*max_element(len,len+n);
	print(L+2,'*'); puts("");
	for ( int i=0; i<n; i++ ) {
		putchar('*');
		int sp=(L-len[i])/2;
		if ( (L-len[i])%2==0 ) {
			print(sp,' ');
			printf("%s",s[i]);
			print(sp,' ');
		} else {
			print(sp+flg,' ');
			printf("%s",s[i]);
			flg^=1;
			print(sp+flg,' ');
		}
		puts("*");
	}
	print(L+2,'*'); puts("");
	return 0;
}