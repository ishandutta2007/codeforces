#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int a[1100];
int n;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int x;
		scanf("%d", &x);
		a[x] ++;
	}
	int mx = 0;
	for (int i = 1; i <= 1000; i ++)
		mx = max(mx, a[i]);
	printf("%d ", mx);
	int res = 0;
	for (int i = 1; i <= 1000; i ++)
		if (a[i] != 0) res ++;
	printf("%d\n", res);
	return 0;
}