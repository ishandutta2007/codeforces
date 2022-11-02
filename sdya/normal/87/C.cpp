#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

int d[110000];

int calc(int n)
{
	vector < int > have;
	for (int i = 2; i * i <= n + n; i ++)
	{
		int a = (((n + n - i * i) / i) - 1) / 2;
		if (a >= 0 && (a + a + i + 1) * i == n + n)
		{
			int cur = 0;
			for (int j = a + 1; j <= a + i; j ++)
				cur ^= d[j];
			have.push_back(cur);
		}
	}
	sort(have.begin(), have.end());
	if (have.size() == 0 || have[0] != 0) return 0;
	for (int i = 1; i < have.size(); i ++)
		if (have[i] > have[i - 1] + 1) return have[i - 1] + 1;
	return have.back() + 1;
}

int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		d[i] = calc(i);

	if (d[n] == 0) printf("-1\n"); else
	{
		for (int i = 2; i * i <= n + n; i ++)
		{
			int a = (((n + n - i * i) / i) - 1) / 2;
			if (a >= 0 && (a + a + i + 1) * i == n + n)
			{
				int cur = 0;
				for (int j = a + 1; j <= a + i; j ++)
					cur ^= d[j];
				if (cur == 0) {printf("%d\n", i); return 0;}
			}
		}
	}
	return 0;
}