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
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


bool angle(int x1, int y1, int x2, int y2)
{
	double n = sqrt(x1*x1 + y1 * y1)*sqrt(x2*x2 + y2 * y2);
	if (n == 0)
	{
		return true;
	}
	double cos = (x1*x2 + y1*y2) / n;
	if (cos >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



signed main()
{

	FAST;
	int n, d, m;
	cin >> n >> d >> m;
	for (int i = 0; i < m; i++)
	{
		int x2, y2;
		cin >> x2 >> y2;
		bool a, b, c, r;
		a = angle(-d, d, x2 - d, y2);
		b = angle(n - d, n - d, x2 - d, y2);
		c = angle(d, -d, x2 - n + d, y2 - n);
		r = angle(d - n, d - n, x2 - n + d, y2 - n);
		if (a && b && c && r)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}