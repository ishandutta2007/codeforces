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
	long long n, s;
	cin >> n >> s;
	vector <int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long res = 0;
	res += abs(s - arr[n / 2]);
	for (int i = 0; i < n / 2; i++)
	{
		if (arr[i] > s)
		{
			res += abs(arr[i] - s);
		}
	}
	for (int i = n / 2 + 1; i < n; i++)
	{
		if (arr[i] < s)
		{
			res += abs(arr[i] - s);
		}
	}
	cout << res;
	return 0;
}