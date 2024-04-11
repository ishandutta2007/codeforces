#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int p[10];
int a[10], b[10];
int n, k, A;

double res = 0.0;

double solve()
{
	double res = 0.0;
	for (int i = 0; i < (1 << n); i ++)
	{
		double s = 1.0;
		int bits = 0, B = 0;
		for (int j = 0; j < n; j ++)
			if (i & (1 << j)) bits ++, s *= (double)(p[j]) / 100.0; else s *= (double)(100 - p[j]) / 100.0, B += a[j + 1];
		if (bits + bits > n) res += s; else
			res += s * (double)(A) / (double)(A + B);
	}
	return res;
}

void rec(int have, int left)
{
	if (have == n)
	{
		res = max(res, solve());
		return ;
	}

	for (int i = 0; i <= left; i ++)
		p[have] = min(100, b[have + 1] + 10 * i), rec(have + 1, left - i);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &k, &A);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &a[i], &b[i]);

	rec(0, k);
	printf("%.10lf\n", res);


	return 0;
}