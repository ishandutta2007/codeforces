#include <iostream>
#include <iomanip>
using namespace std;

const int N = 211111;

int a[N];
double weakness(double x, int n)
{
	double sum = 0;
	double last_min = 0;
	double last_max = 0;
	double ans_min = 0;
	double ans_max = 0;
	for(int i = 0; i < n; i ++)
	{
		sum += a[i] - x;
		ans_max = max(ans_max, sum - last_min);
		ans_min = min(ans_min, sum - last_max);
		last_min = min(last_min, sum);
		last_max = max(last_max, sum);
	}
	return max(ans_max, -ans_min);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	double left = -20000.0;
	double right = 20000.0;
	for(int t = 0; t < 200; t ++)
	{
		double mid1 = (left * 2 + right) / 3;
		double mid2 = (left + right * 2) / 3;
		double w1 = weakness(mid1, n);
		double w2 = weakness(mid2, n);
		if(w1 > w2)
			left = mid1;
		else
			right = mid2;
	}
	cout << setprecision(12) << weakness(left, n) << '\n';
	return 0;
}