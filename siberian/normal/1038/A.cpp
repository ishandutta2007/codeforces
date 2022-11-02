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

char strok[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

signed main()
{
	string s;
	int n, k;
	cin >> n >> k >> s;
	vector <int> x(k, 0);
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (s[i] == strok[j])
			{
				x[j]++;
				break;
			}
		}
	}
	int min = 1000000000;
	for (int i = 0; i < k; i++)
	{
		if (x[i] < min)
			min = x[i];
	}
	cout << min*k;
	return 0;
}