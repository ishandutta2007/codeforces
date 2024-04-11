#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

using namespace std;


typedef long long LL;

int month(int x)
{
	vector<int> m = {31,29,31,30,31,30,31,31,30,31,30,31};
	int r = 0;
	for (auto z : m)
	{
		if (x <= z) r++;
	}
	return r;
}

int week(int x)
{
	x--;
	int r = 0;
	for (int d = 0; d < 366; d++)
	{
		if ((d+4)%7 == x)
			r++;
	}
	return r;
}

int main()
{
	int x;
	string s1, s2;
	cin >> x >> s1 >> s2;
	if (s2 == "week")
	{
		cout << week(x);
	}
	else
	{
		cout << month(x);
	}
	cout << endl;
	exit(0);
}