#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

	long long n, p;
	vector< pair<long long, long long> > arr;

bool can(double x)
{
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].second > x * arr[i].first)
		{
			continue;
		}
		res += (x * arr[i].first - arr[i].second) / p;
	}

	return res <= x;
}

void solve()
{
	cin >> n >> p;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &arr[i].first, &arr[i].second);
	}

	double lf = 0;
	double rg = 1e16;
	for (int z = 0; z < 300; z++)
	{
		double middle = (lf + rg) / 2;
		if (can(middle))
		{
			lf = middle;
		}
		else
		{
			rg = middle;
		}
	}

	if (lf > 1e15)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << setprecision(20) << fixed << lf << endl;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	solve();

	return 0;
}