#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, k, a, b, last;

char s[maxn];

int main()
{
	scanf( "%d%d%d%d", &n, &k, &a, &b );
	int cnt = 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		if( cnt == k )
		{
			if( last )// last == 1: a---G
			{
				if( !b ) return printf("NO\n"), 0;
				else s[ i ] = 'B', b--, cnt = 1, last = 0;
			}
			else
			{
				if( !a ) return printf("NO\n"),0;
				else s[ i ] = 'G', a--, cnt = 1, last = 1;
			}
		}
		else
		{
			if( a >= b )
			{
				s[ i ] = 'G';
				if( !last ) cnt = 0;
				cnt++;
				a--;
				last = 1;
			}
			else
			{
				s[ i ] = 'B';
				if( last ) cnt = 0;
				cnt++;
				b--;
				last = 0;
			}
		}
	}
	for( int i = 1 ; i <= n ; i++ ) printf("%c",s[ i ]);
}