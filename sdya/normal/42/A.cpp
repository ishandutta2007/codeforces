#include <iostream>

using namespace std;

int n;
double V;
double a[30];
double b[30];

int main()
{
	scanf("%d", &n);
	cin >> V;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		cin >> b[i];
	double l = 0.0, r = V;
	int t = 0;
	double s = 0.0;
	while (t < 60)
	{
		double key = (l + r) / 2.0;
		bool good = true;
		s = 0.0;
		for (int i = 1; i <= n; s += a[i] * key, i ++)
			if (a[i] * key > b[i]) good = false;
		if (s > V) good = false;
		if (good)
			l = key; else
			r = key;
		t ++;
	}
	printf("%.10lf\n", s);
	return 0;
}