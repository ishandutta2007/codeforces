// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%g\n",4*(sqrt(a*b/c)+sqrt(a*c/b)+sqrt(b*c/a)));
	return 0;
}