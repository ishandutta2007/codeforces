#include <bits/stdc++.h>

using  namespace std;

int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	k = 240 - k;
	for( int i = 1 ; i <= n ; i++ )
		if( k >= 5 * i )
			k -= 5 * i, ans++;
	cout << ans <<endl;
}