#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
int a[1100], b[1100], c[1100], d[1100];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	int best = 2000000000, u = 1;
	for (int i = 1; i <= n; i ++)
	{
		bool good = true;
		for (int j = 1; j <= n; j ++)
			if (a[j] > a[i] && b[j] > b[i] && c[j] > c[i]) good = false;
		if (good && d[i] < best)
			best = d[i], u = i;
	}

	cout << u << endl;
	return 0;
}