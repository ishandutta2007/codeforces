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

int a[102];
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k, t;
	scanf("%d%d%d", &n, &k, &t);
	int x = n * t / 100;
	int y = n * k * t / 100 - x * k;
	if (x == n)
	{
		FOR(i, n)
			a[i] = k;
	}
	else
	{
		FOR(i, x)
			a[i] = k;
		a[x] = y;
		for (int i = x + 1; i < n; ++i)
			a[i] = 0;
	}
	FOR(i, n)
		printf("%d ", a[i]);
	return 0;
}