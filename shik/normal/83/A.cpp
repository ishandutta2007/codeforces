// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int num[N];
int main()
{
	int n,i,j;
	long long ans=0;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%d",num+i);
	for ( i=0; i<n; i=j ) {
		for ( j=i; j<n && num[i]==num[j]; j++ );
		ans+=(long long)(j-i)*(j-i+1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}