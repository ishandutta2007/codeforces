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
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << "No\n";
		return 0;
	}
	if (n % 2 == 0)
	{
		cout << "Yes\n";
		cout << n / 2 << " ";
		for (int i = 1; i < n; i += 2)
		{
			cout << i << " ";
		}
		cout << endl;
		cout << n / 2 << " ";
		for (int i = 2; i <= n; i += 2)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << "Yes\n";
		cout << 2 << " " << 1 << " " << n << " " << endl;
		cout << n - 2 << " ";
		for (int i = 2; i < n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}