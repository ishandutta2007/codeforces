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
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> lr(n, -1), lc(m, -1);
	vector<int> lrcol(n, 0), lccol(m, 0);


	for (int i = 0; i < k; i++)
	{
		int op, num, col;
		cin >> op >> num >> col;
		num--;
		if (op == 1)
		{
			lr[num] = i;
			lrcol[num] = col;
		}
		else
		{
			lc[num] = i;
			lccol[num] = col;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lr[i] == lc[j])
				cout << 0;
			else if (lr[i] > lc[j])
				cout << lrcol[i];
			else
				cout << lccol[j];
			if (j == m-1) cout << endl; else cout << " ";
		}
	}


}