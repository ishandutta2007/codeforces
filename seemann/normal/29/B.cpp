#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//freopen("", "w", stderr);
	int l, d, v, g, r;
	scanf("%d%d%d%d%d", &l, &d, &v, &g, &r);
	double t = ((double)d) / v;
	double w = t;
	while (w - g - r > - EPS)
		w -= g + r;
	if (w - g > -EPS)
		t += ((double)(g + r)) - w;
	t +=  ((double)l - d) / v;
	printf("%.6lf", t);
	return 0;
}