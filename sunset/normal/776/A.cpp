#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int n;

int main()
{
	cin >> a >> b >> n;
	cout << a << ' ' << b << endl;
	while( n-- )
	{
		cin >> c;
		if( c == a ) cin >> a, cout << a << ' ' << b << endl;
		else cin >> b, cout << a << ' ' << b << endl;
	}
}