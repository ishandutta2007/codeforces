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

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i ++)
		if (4 * i <= n && (n - 4 * i) % 7 == 0)
		{
			for (int j = 0; j < i; j ++)
				printf("4");
			int m = (n - 4 * i) / 7;
			for (int j = 0; j < m; j ++)
				printf("7");
			printf("\n");
			return 0;
		}
	printf("-1\n");
	return 0;
}