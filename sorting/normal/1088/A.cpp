#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;

	cin >> x;

	for(int a = 1; a <= x; a ++)
		for(int b = 1; b <= x; b ++)
			if(a % b == 0 && a*b >x && a < x*b)
			{
				cout << a << " " << b << "\n";

				return 0;
			}

	cout << "-1\n";

	return 0;
}