// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef unsigned long long LL;
int main()
{
	LL a,b;
	scanf("%I64u%I64u",&a,&b);
	LL x=(a-b)/2,y=x+b;
	if ( x+y==a && (x^y)==b ) printf("%I64u %I64u\n",x,y);
	else puts("-1");
	return 0;
}
// a = x + y
// b = x ^ y
// x = t, y = t + b
// 2*t + b = a
// t = (b-a)/2