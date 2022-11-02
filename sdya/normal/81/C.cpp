#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

vector < int > s[10];
int n, a[210000];
int b[210000];

int x, y;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), s[a[i]].push_back(i);
	if (x < y)
	{
		for (int i = 1; i <= n; i ++) b[i] = 2;
		int t = x;
		for (int i = 5; i >= 1 && t != 0; i --)
			for (int j = 0; j < s[i].size() && t != 0; j ++)
				b[s[i][j]] = 1, t --;

	} else
	if (x > y)
	{
		for (int i = 1; i <= n; i ++) b[i] = 1;
		int t = y;
		for (int i = 5; i >= 1 && t != 0; i --)
			for (int j = (int)(s[i].size()) - 1; j >= 0 && t != 0; j --)
				b[s[i][j]] = 2, t --;
	} else
	{
		for (int i = 1; i <= n; i ++) b[i] = 2;
		for (int i = 1; i <= x; i ++) b[i] = 1;
	}

	for (int i = 1; i <= n; i ++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}