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
	int n;
	cin >> n;
	vector <long long> s(n);
	bool flag = false, all = false;
	long long mini = 1e10;
	int pos = -1;
	if (n == 1)
	{
		long long x;
		cin >> x;
		cout << x;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i] < 0)
		{
			flag = true;
		}
		if (s[i] >= 0)
		{
			all = true;
		}
	}
	

	if (flag && all)
	{
		long long res = 0;
		for (int i = 0; i < n; i++)
		{
			res += abs(s[i]);
		}
		cout << res << endl;
		return 0;
	}
	else
	{
		if (!all)
		{
			for (int i = 0; i < n; i++)
			{
				s[i] = abs(s[i]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			mini = min(s[i], mini);
			if (s[i] == mini)
			{
				pos = i;
			}
		}
		if (pos == 0)
		{
			for (int i = 1; i < n - 1; i++)
			{
				s[0] -= s[i];
			}
			s[n - 1] -= s[0];
			cout << s[n - 1] << endl;
			return 0;
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if (i != pos)
				{
					s[pos] -= s[i];
				}
			}
			s[0] -= s[pos];
			cout << s[0] << endl;
			return 0;
		}
	}
	return 0; 
}