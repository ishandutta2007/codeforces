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

typedef pair<int,int> pi;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	if (n > a*b)
	{
		cout << -1 << endl;
		exit(0);
	}
	int nw = 0, nb = 0;
	for (int i = 0; i < a; i++)
	{
		nw += b/2;
		nb += b/2;
		if (b%2 == 0)
		{
			continue;
		}
		nw += i%2 == 0;
		nb += i%2 == 1;
	}
	int d = n/2, r = n/2;
	d += n%2 == 1;
	if (d > nw || r > nb)
	{
		cout << -1 << endl;
		exit(0);
	}
	int A[101][101];
	memset(A, 0, sizeof(A));

	int k = 1;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (k > n) continue;
			if ((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1))
			{
				A[i][j] = k;
				k += 2;
			}
		}
	}
	k = 2;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (k > n) continue;
			if ((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)) continue;
			A[i][j] = k;
			k += 2;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << A[i][j] << (j < b-1 ? " " : "");
		}
		cout << endl;
	}
	exit(0);

}