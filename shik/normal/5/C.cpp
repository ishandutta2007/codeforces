// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int stk[N],top=-1,mat[N];
int main()
{
	int n=strlen(gets(s));
	for ( int i=0; i<n; i++ ) {
		if ( s[i]=='(' ) stk[++top]=i;
		else if ( top>=0 ) mat[i]=stk[top--];
		else mat[i]=i+1;
	}
	for ( int i=0; i<n; i++ ) if ( s[i]==')' && mat[i]>0 && s[mat[i]-1]==')' ) mat[i]=mat[mat[i]-1];
	int ans=0,cnt=0;
	for ( int i=0; i<n; i++ ) if ( s[i]==')' ) ans=max(ans,i-mat[i]+1);
	for ( int i=0; i<n; i++ ) if ( s[i]==')' && i-mat[i]+1==ans ) cnt++;
	printf("%d %d\n",ans,ans==0?1:cnt);
	return 0;
}