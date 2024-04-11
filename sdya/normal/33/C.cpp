#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <map>
#include <set>

using namespace std;

int n;
int a[200000], s[200000], d[200000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	int res = 0;
	for (int i = 1; i <= n; i ++)
		res += a[i];

	int c = 0;
	for (int i = 1; i <= n; i ++)
	{
		d[i] = -2000000000;
		d[i] = max(d[i], a[i]);
		d[i] = max(d[i], a[i] + d[i - 1]);
		c = max(c, d[i]);
	}

	cout << -res + c + c << endl;

	return 0;
}