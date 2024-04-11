// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[100010],f1,f2;
int main()
{
	int n,ans=0;
	scanf("%s%d",s,&n);
	while ( n-- ) {
		scanf(" %c%c",&f1,&f2);
		for ( int i=0,j=0; s[i]; i=j ) {
			if ( s[i]!=f1 && s[i]!=f2 ) {
				j=i+1;
				continue;
			}
			int c1=0,c2=0;
			while ( s[j]==f1 || s[j]==f2 ) {
				if ( s[j]==f1 ) c1++;
				else c2++;
				j++;
			}
			ans+=min(c1,c2);
		}
	}
	printf("%d\n",ans);
	return 0;
}