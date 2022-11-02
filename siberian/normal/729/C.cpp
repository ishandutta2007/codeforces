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
int n, k, s, t;
vector<pair<int, int> > a;
vector <int> g;
void read()
{
	cin >> n >> k >> s >> t;
	a.resize(n);
	g.resize(k);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> g[i];
	}
	sort(a.begin(), a.end());
	sort(g.begin(), g.end());
	g.push_back(s);
}

int ans = -1;

bool check(int x)
{
	int time = 0;
	int pos = 0;
	for (int i = 0; i <= k; i++)
	{
		int l = g[i] - pos;
		if (x >= 2 * l)
			time += l;
		else if (x >= l)
			time += 2 * l - (x - l);
		else
			return false;
		pos = g[i];
	}

	return time <= t;
}

void run()
{
	int l = 0, r = s, m;
	while (l < r - 1)
	{
		m = l + (r - l) / 2;
		if (check(m))
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	//	cout << r << endl;
	if (check(r - 1))
		r--;

	//	cout << r << endl;
	ans = 1e14;
	for (auto i : a)
	{
		if (i.first >= r)
		{
			ans = min(ans, i.second);
		}
	}
	if (ans == 1e14)
		ans = -1;
	if (!check(r))
		ans = -1;
}

void write()
{
	cout << ans;
}

signed main()
{
	FAST;
	read();
	run();
	write();
	return 0;
}