// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,num[N];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",num+i);
	int s=0,all=accumulate(num,num+n,0),ans=0;
	for ( int i=0; i<n-1; i++ )
		if ( (s+=num[i])*2==all ) ans++;
	printf("%d\n",ans);
	return 0;
}