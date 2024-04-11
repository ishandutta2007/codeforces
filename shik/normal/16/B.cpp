// by shik
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct S { int a,b; } s[20];
bool operator < ( const S &a, const S &b ) { return a.b>b.b; }
int main()
{
	int n,m,i;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for ( i=0; i<m; i++ ) scanf("%d%d",&s[i].a,&s[i].b);
	sort(s,s+m);
	for ( i=0; i<m; i++ ) {
		ans+=(long long)(min(n,s[i].a))*s[i].b;
		n-=min(n,s[i].a);
	}
	printf("%I64d\n",ans);
	return 0;
}