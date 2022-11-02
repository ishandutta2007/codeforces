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

int a[110000], g[110000], b[110000];
int pos[110000];
int n;

set < pair < int, int > > S;

bool good(int x)
{
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

vector < pair < int, int > > res;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d", &n);
	//n = 10000;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		//a[i] = rand() + 1;
		b[i] = a[i], g[i] = good(a[i]), S.insert(make_pair(a[i], i));
	}

	bool nice = true;
	for (int i = 2; i <= n; i ++)
		if (a[i] < a[i - 1]) nice = false;
	if (nice)
	{
		printf("0\n");
		return 0;
	}

	int t = 0;
	for (int i = 1; i <= n; i ++)
		t += g[i];
	if (t == 0)
	{
		printf("-1\n");
		return 0;
	}

	int start = 0, old;
	
	int m = 0;
	for (set < pair < int, int > > :: iterator it = S.begin(); it != S.end(); it ++)
		m ++, a[it->second] = m, pos[m] = it->second;

	for (int i = 1; i <= n; i ++)
		if (g[i])
			start = a[i];
	old = start;

	for (int i = 1; i <= m; i ++)
		if (start != i && pos[i] != i)
		{
			if (pos[start] != i)
			{
				int u = start, v = a[i];
				res.push_back(make_pair(pos[u], pos[v]));
				swap(a[pos[u]], a[pos[v]]);
				swap(pos[u], pos[v]);
			}

			int u = start, v = i;
			res.push_back(make_pair(pos[u], pos[v]));
			swap(a[pos[u]], a[pos[v]]);
			swap(pos[u], pos[v]);
		}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i ++)
		printf("%d %d\n", res[i].first, res[i].second);

	/*for (int i = 0; i < res.size(); i ++)
	{
		int u = res[i].first;
		int v = res[i].second;
		if (!good(b[u]) && !good(b[v]))
		{
			cerr << "BAD!!!" << endl;
		}
		swap(b[u], b[v]);
	}
	for (int i = 2; i <= n; i ++)
		if (b[i] < b[i - 1])
			cerr << "BAD!!!" << endl;

	if (res.size() > 2 * n)
		cerr << "BAD!!!" << endl;*/
	return 0;
}