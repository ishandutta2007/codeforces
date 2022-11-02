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
	long long n;
	cin >> n;
	vector <long long> a(n), b(n);
	long long summ_a = 0, summ_b = 0;

	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (long long i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	long long pos_a = 0, pos_b = 0;
	bool flag_a = false, a1 = false;
	bool flag_b = false, b1 = false;
	while (true)
	{
		if (a[pos_a] > b[pos_b])
		{
			summ_a += a[pos_a];
			pos_a++;
		}
		else
		{
			pos_b++;
		}

		if (pos_b == n || pos_a == n)
		{
			flag_b = true;
			break;
		}

		if (a[pos_a] > b[pos_b])
		{
			pos_a++;
		}
		else
		{
			summ_b += b[pos_b];
			pos_b++;
		}
		if (pos_b == n || pos_a == n)
		{
			flag_a = true;
			break;
		}
	}
	if (pos_a == n)
	{
		a1 = true;
	}
	if (pos_b == n)
	{
		b1 = true;
	}

	if (flag_a)
	{
		if (a1)
		{
			for (long long i = pos_b; i < n; i++)
			{
				i++;
				if (i == n)
				{
					break;
				}
				summ_b += b[i];
			}
		}
		else
		{
			for (long long i = pos_a; i < n; i++)
			{
				summ_a += a[i];
				i++;
				if (i == n)
				{
					break;
				}
			}
		}
	}
	else
	{
		if (a1)
		{
			for (long long i = pos_b; i < n; i++)
			{
				summ_b += b[i];
				i++;
				if (i == n)
				{
					break;
				}
			}
		}
		else
		{
			for (long long i = pos_a; i < n; i++)
			{
				i++;
				if (i == n)
				{
					break;
				}
				summ_a += a[i];
			}
		}
	}
	cout << summ_a - summ_b;
	return 0;
}