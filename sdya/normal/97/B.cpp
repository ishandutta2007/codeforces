#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

set < pair < int, int > > S;

pair < int, int > a[11000];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		S.insert(a[i]);
	for (int i = 1; i <= n; i ++)
	{
		int mn = 2000000000, mx = -2000000000;
		for (int j = i + 1; j <= n; j ++)
		{
			if (a[j].second > a[i].second)
			{
				if (a[j].second < mn && a[j].first != a[i].first)
					S.insert(make_pair(a[i].first, a[j].second));
			} else
			if (a[j].second < a[i].second)
			{
				if (a[j].second > mx && a[j].first != a[i].first)
					S.insert(make_pair(a[i].first, a[j].second));
			}

			if (a[j].second >= a[i].second) mn = min(mn, a[j].second);
			if (a[j].second <= a[i].second) mx = max(mx, a[j].second);
		}
	}

	printf("%d\n", S.size());
	for (set < pair < int, int > > :: iterator it = S.begin(); it != S.end(); it ++)
		printf("%d %d\n", it->first, it->second);
	return 0;
}