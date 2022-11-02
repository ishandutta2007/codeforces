#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair < long long, long long > x[4000];
long long d[4000];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		cin >> x[i].first >> x[i].second;

	sort(x + 1, x + n + 1);

	d[n] = x[n].second;
	for (int i = n - 1; i >= 1; i --)
	{
		d[i] = 1000000000000000000LL;
		long long s = 0;
		for (int j = i + 1; j <= n; j ++)
			d[i] = min(d[i], s + d[j]), s += x[j].first - x[i].first;
		d[i] = min(d[i], s);
		d[i] += x[i].second;
	}

	cout << d[1] << endl;
	return 0;
}