#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n;
long long x[2000], y[2000], t[2000];
double p[2000];
double d[2000];
int num[2000];

bool comp(int a, int b)
{
	return t[a] < t[b];
}

long long dist(long long x1, long long y1, long long x2, long long y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		cin >> x[i] >> y[i] >> t[i] >> p[i];
		num[i] = i;
	}
	sort(num + 1, num + n + 1, comp);

	d[0] = 0.0;
	for (int i = 1; i <= n; i ++)
	{
		d[i] = p[num[i]];
		for (int j = 1; j < i; j ++)
			if (dist(x[num[i]], y[num[i]], x[num[j]], y[num[j]]) <= (t[num[i]] - t[num[j]]) * (t[num[i]] - t[num[j]]))
				d[i] = max(d[i], d[j] + p[num[i]]);
	}

	double best = 0.0;
	for (int i = 1; i <= n; i ++)
		best = max(best, d[i]);

	printf("%.10lf\n", best);

	return 0;
}