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
#include <algorithm>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr);



signed main()
{

	FAST;
	long long n, m, k;
	long double s;
	cin >> n >> m >> k;
	if (n*m*2 % k != 0)
	{
		cout << "NO";
		return 0;
	}
	long long s1;
	s1 = n * m * 2 / k;
	s = sqrt(n);
	set <long long> a;
	for (long long i = 1; i <= s; i++)
	{
		if (n % i == 0)
		{
			a.insert(i);
			a.insert(n / i);
		}
	}
	s = sqrt(m);
	for (long long i = 1; i <= s; i++)
	{
		if (m % i == 0)
		{
			a.insert(i);
			a.insert(m / i);
		}
	}

	for (auto i: a)
	{
		if (s1 % i == 0)
		{
			if (max(n, m) >= max(i, s1 / i) && min(n, m) >= min(i, s1 / i))
			{
				cout << "Yes\n";
				cout << "0 0\n";
				if (n > m)
				{
					cout << max(i, s1 / i) << " 0\n";
					cout << "0 " << min(i, s1 / i) << endl;
				}
				else
				{
					cout << "0 " << max(i, s1 / i) << endl;
					cout << min(i, s1 / i) << " 0\n";
				}
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}