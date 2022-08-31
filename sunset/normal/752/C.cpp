#include <bits/stdc++.h>

using namespace std;

const int maxn = 200020;

char ch[maxn];

int n, h, l, ans;

int main()
{
	scanf( "%d%s", &n, ch + 1 );
	for( int i = 1 ; i <= n ; i++ )
	{
		if( ch[ i ] == 'R' )
		{
			if( !h ) h = 1;
			else if( h == -1 ) ans++, l = 0, h = 1;
		}
		else if( ch[ i ] == 'L' )
		{
			if( !h ) h = -1;
			else if( h == 1 ) ans++, l = 0, h = -1;
		}
		else if( ch[ i ] == 'U' )
		{
			if( !l ) l = 1;
			else if( l == -1 ) ans++, l = 1, h = 0;
		}
		else if( ch[ i ] == 'D' )
		{
			if( !l ) l = -1;
			else if( l == 1 ) ans++, l = -1, h = 0;
		}
	}
	cout << ans + 1 << endl;
}