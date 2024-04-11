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

bool used[2000];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int c = 0;
	used[c] = true;
	for (int i = 1; i <= 2000000; i ++)
		c += i, c %= n, used[c] = true;

	for (int i = 0; i < n; i ++)
		if (!used[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}