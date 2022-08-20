#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

map < LL, int > mp;
LL s, n, k, x, ans;

int main()
{
	cin >> n >> k;
	mp[ 0 ] = 1;
	while( n-- )
	{
		cin >> x;
		s += x;
		for( LL c = 1, cnt = 0 ; c <= 1e16 ; c *= k, cnt++ )
		{
			if( k == 1 && cnt ) break;
			if( k == -1 && cnt == 2 ) break;
			ans += mp[ s - c ];
		}
		mp[ s ]++;
	}
	cout << ans << endl;
}