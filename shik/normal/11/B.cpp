// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,s=0;
	scanf("%d",&n);
	n=abs(n);
	for ( int i=0; 1==1; i++ ) {
		s+=i;
		if ( s>=n && (s-n)%2==0 ) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}