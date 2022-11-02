// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,s=0,c[2]={};
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&x);
		s+=x;
		c[x&1]++;
	}
	printf("%d\n",c[s&1]);
	return 0;
}