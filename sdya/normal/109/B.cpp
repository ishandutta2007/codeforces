#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

using namespace std;

int pl, pr, vl, vr, k;
vector < int > a;

void gen(long long x)
{
	if (x > 1000000000) return ;
	if (x != 0) a.push_back(x);

	gen(x * 10 + 4);
	gen(x * 10 + 7);
}

double get(int l, int r, int a, int b)
{
	l = max(l, a);
	r = min(r, b);
	if (l > r) return 0.0;
	return (double)(r - l + 1) / (double)(b - a + 1);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> pl >> pr >> vl >> vr >> k;
	gen(0);
	sort(a.begin(), a.end());
	int n = a.size();
	double res = 0.0;
	for (int i = 0; i < n; i ++)
	{
		if (i + k - 1 >= n) continue;
		int x = a[i];
		int y = a[i + k - 1];

		int l1 = (i == 0 ? 1 : a[i - 1] + 1);
		int r1 = a[i];

		int l2 = a[i + k - 1];
		int r2 = (i + k - 1 == n - 1 ? 1000000000 : a[i + k] - 1);

		res += get(l1, r1, pl, pr) * get(l2, r2, vl, vr);
		res += get(l2, r2, pl, pr) * get(l1, r1, vl, vr);

		if (r1 == l2)
			res -= get(r1, l2, pl, pr) * get(r1, l2, vl, vr);
	}

	printf("%.10lf\n", res);
	return 0;
}