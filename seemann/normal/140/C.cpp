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
const int MAXN = 1e5 + 1;
struct st{
	int c;
	int n;
};

bool operator < (const st & a, const st & b)
{
	if (a.c != b.c)
		return a.c > b.c;
	return a.n < b.n;
}

int a[MAXN];
set<st> b;
int ans[MAXN][3];
int ca = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);

	int n;
	cin >> n;
	FOR(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int cnt = 0;
	FOR(i, n)
		if (i < n - 1 && a[i] == a[i + 1])
			cnt++;
		else
		{
			cnt++;
			st w;
			w.c = cnt;
			cnt = 0;
			w.n = a[i];
			b.insert(w);
		}
	ca = 0;
	while (true)
	{
		iter(b) it = b.begin();
		st a[3];
		bool ind = true;
		FOR(i, 3)
		{
			if (it == b.end())
			{
				ind = false;
				break;
			}
			a[i] = *it;
			b.erase(*it);
			it = b.begin();
		}
		if (!ind)
			break;
		FOR(i, 3)
			ans[ca][i] = a[i].n;
		sort(ans[ca], ans[ca] + 3);
		FOR(i, 3)
			a[i].c--;
		FOR(i, 3)
			if (a[i].c > 0)
				b.insert(a[i]);
		ca++;
	}
	printf("%d\n", ca);
	FOR(i, ca)
	{
		for (int j = 2; j >= 0; --j)
			printf("%d ", ans[i][j]);
		printf("\n");
	}


	return 0;
}