#include <bits/stdc++.h>

using namespace std;

char s1[1234],s2[1234];

int mp[26],vis[26],cnt;

int main()
{
	memset( mp, -1, sizeof(mp) );
	scanf( "%s%s",s1 + 1, s2 + 1 );
	for( int i = 1 ; s1[ i ] ; i++ )
	{
		if( mp[ s1[ i ] - 'a' ] != -1 && mp[ s1[ i ] - 'a' ] != s2[ i ] - 'a' ) return puts( "-1" ), 0;
		if( mp[ s2[ i ] - 'a' ] != -1 && mp[ s2[ i ] - 'a' ] != s1[ i ] - 'a' ) return puts( "-1" ), 0;
		mp[ s1[ i ] - 'a' ] = s2[ i ] - 'a';
		mp[ s2[ i ] - 'a' ] = s1[ i ] - 'a';
	}
	for( int i = 0 ; i < 26 ; i++ ) if( mp[ i ] != -1 && mp[ i ] != i ) cnt++;
	printf( "%d\n", cnt/2 );
	for( int i = 0 ; i < 26 ; i++ )
		if( !vis[ i ] && mp[ i ] != -1 && mp[ i ] != i )
			printf( "%c %c\n", i + 'a', mp[ i ] + 'a' ), vis[ mp[ i ] ] = 1;
}