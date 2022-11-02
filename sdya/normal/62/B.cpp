#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <bitset>

using namespace std;

char s[210000], c[210000];
int n, k;
vector < int > p[50];

long long add(int v, int k)
{
	int l = 0, r = p[v].size() - 1;
	int res = abs(p[v][0] - k);
	res = min(res, abs(p[v].back() - k));
	while (r - l > 1)
	{
		int key = (l + r) / 2;
		if (p[v][key] <= k)
			l = key; else r = key;
	}
	res = min(res, abs(p[v][l] - k));
	res = min(res, abs(p[v][r] - k));
	return res;
}

long long solve()
{
	long long res = 0;
	int n = strlen(c);
	for (int i = 0; i < n; i ++)
	{
		int v = c[i] - 'a';
		if (p[v].size() == 0) res += (long long)(n); else res += add(v, i);
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d\n", &n, &k);
	gets(s);
	for (int i = 0; i < k; i ++)
		p[s[i] - 'a'].push_back(i);
	for (int i = 1; i <= n; i ++)
	{
		gets(c);
		printf("%I64d\n", solve());
	}
	return 0;
}