#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int d,a,b,c;
		cin >> a >> b >> c;
		d=a-b;
		if(d<0) d=-d;
		if(a>d+d||b>d+d||c>d+d)
		{
			cout << "-1\n";
			continue;
		}
		if(c>d) cout << c-d << "\n";
		else cout << c+d << "\n";
	}
	return 0;
}