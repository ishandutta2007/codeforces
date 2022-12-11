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
const int MAXK = 200;
int ans[MAXK][MAXK];


int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	int k = 3;
	while (k * (k - 1) / 2 <= n)
		k++;
	k--;
	int w = 1;
	printf("%d\n", k);
	FOR(i, k)
	{
		FOR(j, i)
			printf("%d ", ans[i][j]);
		for (int j = i + 1; j < k; ++j)
		{
			printf("%d ", w);
			ans[j][i] = w;
			w++;
		}
		printf("\n");
	}
	return 0;
}