// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[1000010];
int t[1000010]={1};
int main()
{
	int k;
	scanf("%d%s",&k,s);
	long long ans=0;
	for ( int i=0,c=0; s[i]; i++ ) {
		c+=(s[i]=='1');
		if ( c>=k ) ans+=t[c-k];
		t[c]++;
	}
	printf("%I64d\n",ans);
	return 0;
}