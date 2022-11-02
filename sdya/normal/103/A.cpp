#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

int n;
long long a[200], d[200];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		d[i] = d[i - 1] + (a[i] - 1LL) * (long long)(i);
	cout << d[n] + n << endl;

	return 0;
}