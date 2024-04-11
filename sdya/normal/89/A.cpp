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

int n, m, k;
int a[11000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	if (n % 2 == 0)
	{
		printf("0\n");
		return 0;
	}
	int mn = 1000000000;
	for (int i = 1; i <= n; i += 2)
		mn = min(mn, a[i]);
	long long have = m / ((n + 1) / 2);
	have *= (long long)(k);
	long long res = min(have, (long long)(mn));
	cout << res << endl;
	return 0;
}