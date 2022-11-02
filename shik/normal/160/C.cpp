// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[N];
int main()
{
	int n,p,c;
	long long k;
	scanf("%d%I64d",&n,&k); k--;
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	p=a[k/n];
	c=count(a,a+n,p);
	k-=1LL*n*(find(a,a+n,p)-a);
	printf("%d %d\n",p,a[k/c]);
	return 0;
}