#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;
	int m;
	cin >> m;
	for(int  i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x + y >= d && x + y <= 2*n - d && x - y <= d && y - x <= d) cout << "YES\n";
		else cout << "NO\n";
	}
}