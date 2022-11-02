// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,s[200],i,ans=0;
	scanf("%d%d",&n,&m);
	for ( i=0; i<n; i++ ) scanf("%d",s+i);
	sort(s,s+n);
	for ( i=0; i<m&&s[i]<0; i++ ) ans+=-s[i];
	printf("%d\n",ans);
	return 0;
}