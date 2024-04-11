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
const int INF= 1000000001;
const int MAXN = 100001;
int a[MAXN];
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
		cin >> a[i];
	sort(a, a + n);
	if (a[n - 1] == 1)
	{
		FOR(i, n - 1)
			printf("%d ", 1);
		printf("2");
		return 0;
	}
	FOR(i, n)
	{
		if (i == 0)
			printf("%d ", 1);
		else
			printf("%d ", a[i - 1]);
	}
	return 0;
}