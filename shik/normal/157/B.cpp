// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double pi=acos(-1);
int main()
{
	int n,r[1010]; double ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",r+i);
	sort(r,r+n);
	for ( int i=n-1; i>=0; i-=2 ) ans+=pi*r[i]*r[i]-(i>0?pi*r[i-1]*r[i-1]:0);
	printf("%.9f\n",ans);
	return 0;
}