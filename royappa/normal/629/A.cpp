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

using namespace std;


typedef long long LL;


int main()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int ii = 0; ii < n; ii++)
			{
				for (int jj = 0; jj < n; jj++)
				{
					if (ii == i && jj == j) continue;
					if (v[i][j] == 'C' && v[ii][jj] == 'C' && (i == ii || j == jj)) num++;
				}
			}
		}
	}
	cout << num/2 << endl;
}