// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define H 131
#define N 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
int pw[N]={1},sh[N];
int get( int st, int ed ) {
	return sh[ed]-sh[st-1]*pw[ed-st+1];
}
int main()
{
	for ( int i=1; i<N; i++ ) pw[i]=pw[i-1]*H;
	int n=strlen(gets(s+1));
	for ( int i=1; i<=n; i++ ) sh[i]=sh[i-1]*H+s[i];
	int big=0;
	for ( int i=2; i<=n; i++ ) {
		int L=0,R=n-i;
		while ( L!=R ) {
			int M=(L+R+1)/2;
			if ( get(1,M)==get(i,i+M-1) ) L=M;
			else R=M-1;
		}
		big=max(big,L);
	}
	for ( int i=big; i>0; i-- ) if ( get(1,i)==get(n-i+1,n) ) {
		s[i+1]=0;
		puts(s+1);
		return 0;
	}
	puts("Just a legend");
	return 0;
}