// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int m,n,a,b;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	a--; b--;
	if ( a/n == b/n ) puts("1");
	else if ( a%n==0 && ((b+1)%n==0||b==m-1) ) puts("1");
	else if ( a/n+1 == b/n ) puts("2");
	else if ( a%n==0 || (b+1)%n==0 || b==m-1 ) puts("2");
	else if ( a%n + (n-(b%n+1)) == n ) puts("2");
	else puts("3");
	return 0;
}