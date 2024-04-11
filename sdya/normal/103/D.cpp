#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

vector < int > c[560];
int n, p;
int w[310000];
int a[310000], b[310000];
long long res[310000];
long long s[310000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &w[i]);
	scanf("%d", &p);
	for (int i = 1; i <= p; i ++)
	{
		scanf("%d%d", &a[i], &b[i]);
		if (b[i] <= 550) c[b[i]].push_back(i); else
		{
			long long cur = 0;
			int A = a[i], B = b[i];
			for (int j = A; j <= n; j += B)
				cur += (long long)(w[j]);
			res[i] = cur;
		}
	}

	for (int i = 1; i <= 550; i ++)
		if (c[i].size() != 0)
		{
			for (int j = 1; j <= n; j ++)
				if (j <= i) s[j] = w[j]; else s[j] = s[j - i] + (long long)(w[j]);

			for (int j = 0; j < c[i].size(); j ++)
			{
				int A = a[c[i][j]];
				int k = (n - A) / i;
				long long s1 = s[A + k * i];
				long long s2 = A - i > 0 ? s[A - i] : 0;
				res[c[i][j]] = s1 - s2;
			}
		}

	for (int i = 1; i <= p; i ++)
		printf("%I64d\n", res[i]);
	return 0;
}