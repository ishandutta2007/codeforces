// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int mat[N],stk[N],top,sum[N];
int main()
{
	memset(mat,-1,sizeof(mat));
	int n=strlen(gets(s));
	for ( int i=0; i<n; i++ ) {
		if ( s[i]=='(' || s[i]=='[' ) stk[top++]=i;
		else if ( s[i]==')' ) {
			if ( top>0 && s[stk[top-1]]=='(' ) mat[i]=stk[--top];
			else top=0;
		} else if ( s[i]==']' ) {
			if ( top>0 && s[stk[top-1]]=='[' ) mat[i]=stk[--top];
			else top=0;
		} else puts("QQ");
	}
	for ( int i=0; i<n; i++ ) if ( mat[i]>0 && mat[mat[i]-1]!=-1 ) mat[i]=mat[mat[i]-1];
	for ( int i=0; i<n; i++ ) sum[i+1]=sum[i]+(s[i]=='[');
	int big=-1,st=0,ed=0;
	for ( int i=0; i<n; i++ ) if ( mat[i]!=-1 ) {
		int l=mat[i],r=i,now=sum[r+1]-sum[l];
		if ( now>big ) {
			big=now;
			st=l; ed=r;
		}
	}
	if ( big==-1 ) {
		puts("0\n");
		return 0;
	}
	printf("%d\n",big);
	for ( int i=st; i<=ed; i++ ) putchar(s[i]);
	puts("");
	return 0;
}