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
	string s1, s2;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			if (s1[i] != s2[i])
			{
				res++;
			}
		}
		else
		{
			if (s1[i] == s2[i])
			{
				continue;
			}
			else if (s1[i] == s2[i + 1] && s1[i + 1] == s2[i])
			{
				res ++;
				i++;
			}
			else
			{
				res++;
			}
		}

	}
	cout << res;
	return 0;
}