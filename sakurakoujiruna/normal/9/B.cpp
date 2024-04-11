#include <iostream>
#include <cmath>
using namespace std;

const int N = 121;
typedef long long intl;
#define double long double
const double Eps = 1e-8;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
int x[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, vb, vs;
	cin >> n >> vb >> vs;
	for(int i = 0; i < n; i ++)
		cin >> x[i];
	int xu, yu;
	cin >> xu >> yu;

	double ans = 1e9;
	int id = 0;
	for(int i = 1; i < n; i ++)
	{
		double tmp = (double)x[i] / vb +
			sqrt((intl)(xu - x[i]) * (xu - x[i]) + (intl)yu * yu) / vs;
		if(sgn(tmp, ans) == -1)
		{
			ans = tmp;
			id = i;
		}
		else if(sgn(tmp, ans) == 0)
			if(sqrt((intl)(xu - x[i]) * (xu - x[i]) + (intl)yu * yu) <
				sqrt((intl)(xu - x[id]) * (xu - x[id]) + (intl)yu * yu))
				id = i;
	}
	cout << id + 1 << '\n';
	return 0;
}