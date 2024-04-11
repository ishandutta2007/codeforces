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

int n;
int a[100002];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%d", &n);
	FOR(i, n)
		scanf("%d", &a[i]);

	for (int i = 3; i <= n; ++i)
	{
		if (n % i != 0) continue;
		int x = n / i;
		FOR(j, x)
		{
			bool ind = true;
			for (int g = j; g < n; g += x)
				if (a[g] == 0) {ind = false; break;}
			if (ind)
			{
				cout << "YES";
				exit(0);
			}
		}
	}
	cout << "NO";
	return 0;
}