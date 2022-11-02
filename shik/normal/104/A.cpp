// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if ( n<=10 || n>21 ) puts("0");
	else if ( n==20 ) puts("15");
	else puts("4");
	return 0;
}