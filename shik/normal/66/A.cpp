// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const long long tbl[]={127,32767,2147483647,9223372036854775807LL};
const char name[][20]={"byte","short","int","long","BigInteger"}; 
int main()
{
	long double n;
	int i;
	cin>>n;
	for ( i=0; i<4; i++ )
		if ( n<=tbl[i] ) break;
	puts(name[i]);
	return 0;
}