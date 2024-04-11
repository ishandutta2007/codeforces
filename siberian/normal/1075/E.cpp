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

#define int long long

int n;
vector <pair<int, int> > a;

void read()
{
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
}

int per3(pair <int, int> a, pair<int, int> b, pair<int, int> c)
{
	return abs(a.first - b.first) + abs(a.second - b.second) + abs(b.first - c.first) + abs(b.second - c.second) + abs(a.first - c.first) + abs(a.second - c.second);
}

int ans3, ans4;

void run()
{
	vector <pair <int, int> > op;
	int minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;
	sort(a.begin(), a.end());

	for (auto i : a)
	{
		maxx = max(maxx, i.first);
		minx = min(minx, i.first);
		maxy = max(maxy, i.second);
		miny = min(miny, i.second);
	}

	pair <int, int> a1, a2, a3, a4;
	a1 = { minx, miny };
	a2 = { minx, maxy };
	a3 = { maxx, miny };
	a4 = { maxx, maxy };

	bool flag = false;

	for (auto i : a)
	{
		if (i.first == minx || i.first == maxx || i.second == miny || i.second == maxy)
		{
			op.push_back(i);
			if (i == a1 || i == a2 || i == a3 || i == a4)
			{
				flag = true;
			}
		}
	}



	if (flag)
	{
		ans3 = (abs(maxx - minx) + abs(maxy - miny)) * 2;
		ans4 = ans3;
	}
	else
	{
		ans3 = 0;
		ans4 = (abs(maxx - minx) + abs(maxy - miny)) * 2;
		for (int i = 0; i < op.size(); i++)
		{
			for (int j = i + 1; j < op.size(); j++)
			{
				for (int k = 0; k < a.size(); k++)
				{
					ans3 = max(per3(op[i], op[j], a[k]), ans3);
				}
			}
		}

	}

}

void write()
{
	cout << ans3 << " ";
	for (int i = 0; i < n - 3; i++)
	{
		cout << ans4 << " ";
	}
}

signed main()
{
	FAST;
	read();
	run();
	write();
	return 0;
}