// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,c[30]={},x;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d",&x);
		c[x+10]++;
	}
	long long ans=0;
	for ( int i=1; i<=10; i++ ) ans+=1LL*c[i+10]*c[-i+10];
	ans+=1LL*c[10]*(c[10]-1)/2;
	cout<<ans<<endl;
	return 0;
}