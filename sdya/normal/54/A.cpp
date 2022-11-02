#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

int n, k, m;
int a[500];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &a[i]);

	int res = m;
	if (m == 0)
	{
		int t = 0;
		while (true)
			if (t + k < n + 1)
				res ++, t += k; else break;
		printf("%d\n", res);
		return 0;
	}

	for (int i = 2; i <= m; i ++)
	{
		int t = a[i - 1];
		while (true)
			if (t + k < a[i]) res ++, t += k; else break;
	}

	int t = 0;
	while (true)
		if (t + k < a[1])
			res ++, t += k; else break;

	t = a[m];
	while (true)
		if (t + k < n + 1)
			res ++, t += k; else break;

	cout << res << endl;

	return 0;
}