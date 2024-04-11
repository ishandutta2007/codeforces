#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

#include <algorithm>

using namespace std;


typedef long long LL;

LL A[1000][1000], B[1000][1000];

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		A[i][i] = a[i];
		for (int j = i+1; j < n; j++)
		{
			A[i][j] = A[i][j-1]|a[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		B[i][i] = b[i];
		for (int j = i+1; j < n; j++)
		{
			B[i][j] = B[i][j-1]|b[j];
		}
	}
	LL best = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (A[i][j]+B[i][j] > best)
			best = max(best, A[i][j]+B[i][j]);
		}
	}
	cout << best << endl;

}