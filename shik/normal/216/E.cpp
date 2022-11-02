// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int a[N];
int main()
{
	LL ans=0,z=0;
	int k,b,n;
	scanf("%d%d%d",&k,&b,&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	map<int,int> c;
	c[0]++;
	int s=0,t=0;
	for ( int i=1; i<=n; i++ ) {
		s=(s+a[i])%(k-1);
		ans+=c[(s-b+k-1)%(k-1)];
		c[s]++;
		if ( a[i]==0 ) z+=++t;
		else t=0;
	}
	if ( b==0 ) ans=z;
	else if ( b==k-1 ) ans-=z;
	cout<<ans<<endl;
	return 0;
}