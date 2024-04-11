// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int t,m,n,idx=0,mem[110]={};
	char op[20];
	scanf("%d%d",&t,&m);
	while ( t-- ) {
		scanf("%s",op);
		if ( op[0]=='a' ) {
			scanf("%d",&n);
			int flg=0;
			for ( int i=1,j; i<=m; i=j ) {
				if ( mem[i]!=0 ) { j=i+1; continue; }
				for ( j=i; j<=m&&mem[j]==0; j++ );
				if ( j-i>=n ) {
					idx++; flg=1;
					for ( int k=0; k<n; k++ ) mem[i+k]=idx;
					break;
				}
			}
			if ( flg ) printf("%d\n",idx);
			else puts("NULL");
		} else if ( op[0]=='e' ) {
			scanf("%d",&n);
			int flg=0;
			if ( n<1 || n>idx ) { puts("ILLEGAL_ERASE_ARGUMENT"); continue; }
			for ( int i=1; i<=m; i++ ) if ( mem[i]==n ) mem[i]=0,flg=1;
			if ( flg==0 ) puts("ILLEGAL_ERASE_ARGUMENT");
		} else if ( op[0]=='d' ) {
			for ( int i=1,j=1; i<=m; i++ ) if ( mem[i]!=0 ) {
				mem[j++]=mem[i];
				if ( i>=j ) mem[i]=0;
			}
		} else puts("QQ");
	}
	return 0;
}