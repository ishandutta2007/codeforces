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
typedef pair<LL,int> ppSize;
typedef pair<int,LL> ppInd;

int main()
{
	int nr, nc, n, k;
	cin >> nr >> nc >> n >> k;
	int A[11][11];
	memset(A, 0, sizeof(A));
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
	}


	int num = 0;

	for (int i = 1; i <= nr; i++)
	{
		for (int j = 1; j <= nc; j++)
		{
			int nv = 0;
			for (int ii = i; ii <= nr; ii++)
			{
				for (int jj = j; jj <= nc; jj++)
				{
					int nv = 0;
					for (int iii = i; iii <= ii; iii++)
					{
						for (int jjj = j; jjj <= jj; jjj++)
						{
							nv += A[iii][jjj];
						}
					}
					if (nv >= k) num++;
				}
			}
		}
	}

	cout << num << endl;
}