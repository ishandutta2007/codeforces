#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long double doublel;

int x[N * 2], y[N * 2];
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> x[i] >> y[i];
		x[i + n] = x[i];
		y[i + n] = y[i];
	}
	
	if(n <= 200)
	{
		doublel side = 0;
		doublel area = 0;
		doublel all = pow(2, n) - n * (n - 1) / 2 - n - 1;
		for(int i = 0; i < n; i ++)
			for(int j = i + 1; j < i + n; j ++)
			{
				//cout << i << ' ' << j << ' ' << gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) << '\n';
				side += (pow(2, n - 1 - (j - i)) - 1) * gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
				area += (pow(2, n - 1 - (j - i)) - 1) * ((doublel)x[i] * y[j] - (doublel)y[i] * x[j]);
			}
		//cout << area << ' ' << side << ' ' << all << '\n';
		cout << setprecision(12) << (abs(area / 2) - side / 2) / all + 1 << '\n';
	}
	else
	{
		doublel side = 0;
		doublel area = 0;
		for(int i = 0; i < n; i ++)
			for(int j = i + 1; j < i + 50; j ++)
			{
				side += pow(2, -(j - i + 1)) * gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
				area += pow(2, -(j - i + 1)) * ((doublel)x[i] * y[j] - (doublel)y[i] * x[j]);
			}
		cout << setprecision(12) << abs(area / 2) - side / 2 + 1 << '\n';
	}
	

	return 0;
}