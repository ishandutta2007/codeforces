// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100
using namespace std;
struct P {
	char name[100];
	int p,m,a,b,c,d,e,sc;
	void read() {
		scanf("%s %d%d%d%d%d%d%d",name,&p,&m,&a,&b,&c,&d,&e);
		sc=p*100-m*50+a+b+c+d+e;	
	}
} p[N];
int main()
{
	int n,i,w;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) p[i].read();
	w=0;
	for ( i=0; i<n; i++ )
		if ( p[i].sc>p[w].sc ) w=i;
	printf("%s\n",p[w].name);
	return 0;
}