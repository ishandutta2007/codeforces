// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,s,f,t,d,k;
	scanf("%d%d",&n,&m);
	d=2*m-2;
	while ( n-- ) {
		scanf("%d%d%d",&s,&f,&t);
		k=t/d*d;
		if ( s==f ) { printf("%d\n",t); continue; }
		if ( s<f ) {
			if ( k+(s-1)<t ) k+=d;
			printf("%d\n",k+f-1);
		} else {
			k+=m-1;
			if ( k+(m-s)<t ) k+=d;
			printf("%d\n",k+m-f);
		}
	}
	return 0;
}