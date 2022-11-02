#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

signed main()
{
	int n, m;
	cin >> n >> m;
	bool flag = false;
	int start, finish;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if (x == 'B' && !flag)
			{
				flag = true;
				start = j;
			}
			if (x == 'W' && flag)
			{
				finish = j;
				int len = (finish - start + 1) / 2;
				cout << i + len << " " << start + len;
				return 0;
			}
			else
			{
				if (x == 'B' && flag && j == m - 1)
				{
					finish = j + 1;
					int len = (finish - start + 1) / 2;
					cout << i + len << " " << start + len;
					return 0;
				}
			}
		}
	}
	return 0;
}