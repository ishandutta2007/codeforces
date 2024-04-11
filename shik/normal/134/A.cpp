// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,a[200010];
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	LL sum=0;
	for ( int i=1; i<=n; i++ ) sum+=a[i];
	vector<int> sol;
	for ( int i=1; i<=n; i++ ) if ( sum-a[i]==a[i]*(n-1LL) ) sol.push_back(i);
	printf("%d\n",SZ(sol));
	for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
	return 0;
}