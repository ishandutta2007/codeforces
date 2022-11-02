// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
char a[N],b[N];
LL sa[26][N],sb[26][N];
int main()
{
	int n;
	scanf("%d%s%s",&n,a+1,b+1);
	double all=1.0*n*(n+1)*(2*n+1)/6,cnt=0;
	for ( int i=0; i<26; i++ ) for ( int j=1; j<=n; j++ ) {
		sa[i][j]=sa[i][j-1]+(a[j]-'A'==i?j:0);
		sb[i][j]=sb[i][j-1]+(b[j]-'A'==i?j:0);
	}
	for ( int i=1; i<=n; i++ ) {
		cnt+=(n-i+1)*(sa[b[i]-'A'][i]+sb[a[i]-'A'][i]);
		if ( a[i]==b[i] ) cnt-=1.0*(n-i+1)*i;
	}
	double ans=cnt/all;
	printf("%.9f\n",ans);
	return 0;
}