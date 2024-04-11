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
const int MAXN = 1001;

int a[MAXN];

int ans[MAXN];
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;	
	int b = 0;
	int mb = 0;
	FOR(i, n - 1)
	{

		a[i] = 0;
		char c;
		scanf(" %c", &c);
		if (c == 'L') b--, a[i] = -1;
		if (c == 'R') b++, a[i] = 1;
		mb = min(b, mb);
	}

	int c = 0;
	while(c < n)
	{
		b = 0;
		int mb = 0;
		int j = c;
		while (j < n - 1 && a[j] <= 0)
		{
			b+= a[j];
			mb = min(b, mb);
			j++;
		}
		ans[c] = -mb;

		if (c != 0) ans[c] = max(ans[c], ans[c - 1] + 1);
		
		for (int i = c + 1; i <= j; ++i)
			if (a[i - 1] == 0) ans[i] = ans[i - 1];
			else  ans[i] = -(++mb);


		c = j + 1;
	}

	FOR(i, n)
	{
		printf("%d ", ans[i] + 1);
	}
	return 0;
}