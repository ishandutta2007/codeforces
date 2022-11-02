#include <bits/stdc++.h>
using namespace std;

const double Pi = 4 * atan(1);

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	int rr, vv;
	double r, v;
	cin >> n >> rr >> vv;
	r = rr;
	v = vv;
	cout << setprecision(8);
	while(n --)
	{
		int ss, tt;
		double s, t;
		cin >> ss >> tt;
		s = ss;
		t = tt;
		s = t - s;
		double sp = fmod(s / r, 2 * Pi);
		if(sp < Pi + 2)
		{
			double left = 0, right = r;
			for(int _ = 0; _ < 55; _ ++)
			{
				double m = (left + right) / 2;
				double t = 2 * asin(m / r) + 2 * m / r;
				if(t < sp)
					left = m;
				else
					right = m;
			}
			cout << (s - 2 * left) / v << '\n';
		}
		else
		{
			double left = 0, right = r;
			for(int _ = 0; _ < 55; _ ++)
			{
				double m = (left + right) / 2;
				double t = -2 * asin(m / r) + 2 * m / r;
				if(t < sp - 2 * Pi)
					right = m;
				else
					left = m;
			}
			cout << (s - 2 * left) / v << '\n';
		}
	}
	return 0;
}