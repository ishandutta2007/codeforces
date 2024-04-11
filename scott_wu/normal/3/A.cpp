#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	char a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int f = (int) (c - a), s = (int) (d - b);
	
	cout << max (abs (f), abs (s)) << "\n";
	for (int i = 0; i < max (abs (f), abs (s)); i++)
	{
		if (i < abs (f))
		{
			if (f < 0)
				cout << "L";
			else
				cout << "R";
		}
		if (i < abs (s))
		{
			if (s < 0)
				cout << "D";
			else
				cout << "U";
		}
		cout << "\n";
	}
	return 0;
}