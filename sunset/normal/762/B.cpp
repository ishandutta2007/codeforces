#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300010;

long long ans;

struct mouse
{
	int val, type;
	bool operator < ( const mouse &b ) const { return val < b.val; }
}e[MAXN];

int a, b, c, n, cnt;

char ch[10];

int main()
{
	scanf( "%d%d%d%d", &a, &b, &c, &n );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d", &e[ i ].val );
		scanf( "%s", ch + 1 );
		if( ch[ 1 ] == 'U' ) e[ i ].type = 0;
		else e[ i ].type = 1;
	}
	sort( e + 1, e + n + 1 );
	for( int i = 1 ; i <= n ; i++ )
	{
		if( e[ i ].type )
		{
			if( b ) b--, cnt++, ans += e[ i ].val;
			else if( c ) c--, cnt++, ans += e[ i ].val;
			else continue;
		}
		else
		{
			if( a ) a--, cnt++, ans += e[ i ].val;
			else if( c ) c--, cnt++, ans += e[ i ].val;
		}
	}
	cout << cnt << " " << ans << endl;
}