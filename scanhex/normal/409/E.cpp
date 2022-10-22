#include <cmath>
#include <iostream>

using namespace std; 

double myabs(double a)
{
	return a < 0 ? -a : a;
}

int main()
{
	double r, b;
	cin >> r;
	for (int a = 0; a <= 10; ++a)
		for (int h = 0; h <= 10; ++h)
		{
			b = (double)a / 2;
			if (myabs(b*h/sqrt(b * b + h * h) - r) < 1e-6)
			{
				cout << a << ' ' << h;
				return 0;
			}
				
		}
}