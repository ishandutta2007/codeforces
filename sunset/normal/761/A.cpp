#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if( abs( a - b ) <= 1 && ( a || b ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
}