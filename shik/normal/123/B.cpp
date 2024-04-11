// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int a,b,x1,y1,x2,y2,p1,q1,p2,q2,s1,t1,s2,t2;
	scanf("%d%d%d%d%d%d",&a,&b,&x1,&y1,&x2,&y2);
	p1=x1+y1; q1=x1-y1;
	p2=x2+y2; q2=x2-y2;
	s1=p1/(2*a)-(p1<0); t1=q1/(2*b)-(q1<0);
	s2=p2/(2*a)-(p2<0); t2=q2/(2*b)-(q2<0);
	printf("%d\n",max(abs(s1-s2),abs(t1-t2)));
	return 0;
}