// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 40
using namespace std;
int L[N],R[N];
int main()
{
	int n,s,a=0,b=0,i;
	scanf("%d%d",&n,&s);
	for ( i=0; i<n; i++ ) scanf("%d%d",L+i,R+i);
	for ( i=0; i<n; i++ ) a+=L[i],b+=R[i];
	if ( s<a || s>b ) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for ( i=0; i<n; i++ ) {
		int t=L[i];
		while ( s-t>b-R[i] ) t++;
		printf("%d%c",t,i==n-1?'\n':' ');
		a-=L[i];
		b-=R[i];
		s-=t;
	}
	return 0;
}