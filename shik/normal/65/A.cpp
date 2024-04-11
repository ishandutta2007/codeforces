// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	double a,b,c,d,e,f;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	if ( a!=0 && c!=0 && e!=0 && (b/a)*(d/c)*(f/e)>1 ) puts("Ron");
	else if ( d==0 ) puts("Hermione");
	else if ( c==0 ) puts("Ron");
	else if ( b==0 ) puts("Hermione");
	else if ( a==0 ) puts("Ron");
	else if ( f==0 ) puts("Hermione");
	else if ( e==0 ) puts("Ron");
	else puts("Hermione");
	return 0;
}