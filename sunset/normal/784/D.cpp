#include <bits/stdc++.h>
using namespace std;

int a[10] = { '8', 'a', 'a', '3', '6', '9', '4', '7', '0', '5' };
int s[10] = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 };

char ch[11];

int main()
{
	scanf( "%s", ch );
	int len = strlen( ch ), i, j;
	for( i = 0, j = len - 1 ; i < j ; i++, j-- )
		if( a[ ch[ i ] - '0' ] != ch[ j ] ) return puts( "No" ), 0;
	if( i == j && !s[ ch[ i ] - '0' ] ) return puts( "No" ), 0;
	puts( "Yes" );
}