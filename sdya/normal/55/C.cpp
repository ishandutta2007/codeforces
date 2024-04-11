#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i ++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (min(abs(a - 1), abs(n - a)) < 5 || min(abs(b - 1), abs(b - m)) < 5)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}