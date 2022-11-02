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


vector <int> cnt(6, 0);
vector <pair <pair <int, int>, int > > x;
int n;
vector <int> ans;

int check(string s)
{
	//S, M, L, XL, XXL, XXXL
	if (s == "S")
		return 0;
	if (s == "M")
		return 1;
	if (s == "L")
		return 2;
	if (s == "XL")
		return 3;
	if (s == "XXL")
		return 4;
	return 5;
}


void read()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> cnt[i];
	}


	cin >> n;
	ans.resize(n, 0);
	for (int j = 0; j < n; j++)
	{
		string s;
		cin >> s;
		string l = "", r = "";
		bool flag = false;
		for (auto i : s)
		{
			if (i == ',')
			{
				flag = true;
			}
			else
			{
				if (flag)
					r += i;
				else
					l += i;
			}
		}
		if (r == "")
		{
			cnt[check(l)]--;
			ans[j] = check(l);
		}
		else
		{
			int a, b;
			a = check(l);
			b = check(r);
			if (a > b)
				swap(a, b);
			x.push_back({ { a, b }, j });
		}
	}
	sort(x.begin(), x.end());
}


void run()
{
	for (auto i : x)
	{
		if (cnt[i.first.first] > 0)
		{
			cnt[i.first.first]--;
			ans[i.second] = i.first.first;
		}
		else
		{
			cnt[i.first.second]--;
			ans[i.second] = i.first.second;
		}
	}
}

string for_out(int s)
{
	//S, M, L, XL, XXL, XXXL
	if (s == 0)
		return "S";
	if (s == 1)
		return "M";
	if (s == 2)
		return "L";
	if (s == 3)
		return "XL";
	if (s == 4)
		return "XXL";
	return "XXXL";
}


void out()
{
	for (auto i : cnt)
		if (i<0)
		{
			cout << "NO";
			exit(0);
		}
	cout << "YES\n";
	for (auto i : ans)
		cout << for_out(i) << endl;
}

signed main()
{
	FAST;
	read();
//	cout << "puhh\n";
	run();
//	cout << "puhh\n";
	out();
	return 0;
}