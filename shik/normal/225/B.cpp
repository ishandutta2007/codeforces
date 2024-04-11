// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int s,k,sol[50],sn=0;
	long long f[50]={0,1};
	scanf("%d%d",&s,&k);
	for ( int i=2; i<50; i++ ) for ( int j=1; j<=k&&j<=i; j++ ) f[i]+=f[i-j];
	int t=1;
	while ( f[t]<s ) t++;
	for ( int i=t; i>=0; i-- )  if ( f[i]<=s ) {
		sol[sn++]=f[i];
		s-=f[i];
	}
	printf("%d\n",sn);
	for ( int i=0; i<sn; i++ ) printf("%d%c",sol[i],i==sn-1?'\n':' ');
	return 0;
}