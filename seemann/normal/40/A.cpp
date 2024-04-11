#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const int _eps = 0.0000000001;


int main()
{
	int x, y;
	cin >> x>> y;
	for (int i = 0; i <= 4000; i++)
		if (i * i == x * x + y * y)
		{
			cout << "black";
			return 0;
		}
	int d;
        for (int i = 0; i <= 4000; i++)

		if (i * i > x * x + y * y)
		{
			d = i - 1;
			break;
		}

	if (x * y > -_eps)
		if (d % 2 == 0)
		{
			cout << "black";
		}
		else cout << "white";
	else
		if (d % 2 == 0)
			cout << "white";
		else cout << "black";
	return 0;

	
}