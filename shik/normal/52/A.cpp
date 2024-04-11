// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,cnt[3]={},x;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&x);
		cnt[x-1]++;
	}
	printf("%d\n",n-*max_element(cnt,cnt+3));
	return 0;
}