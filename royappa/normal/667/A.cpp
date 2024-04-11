#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


int main()
{
	double d, h, v, e;
	cin >> d >> h >> v >> e;
	double pi = atan(1.0)*4.0;
	double volume = pi*(d/2)*(d/2)*h; // cubic cm
	double erate = pi*(d/2)*(d/2)*e; // cubic cm/s

	if (erate >= v)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		printf("%.8lf\n", volume/(v-erate));
	}
	exit(0);
}