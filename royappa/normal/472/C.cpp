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


//http://codeforces.com/contest/472/problem/C

using namespace std;


typedef long long LL;


int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "YES";
		exit(0);
	}
	vector<string> ha(n), hb(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ha[i] >> hb[i];
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	string last = min(ha[p[0]], hb[p[0]]);
	for (int i = 1; i < n; i++)
	{
		string mi, mx;
		if (ha[p[i]] < hb[p[i]])
		{
			mi = ha[p[i]];
			mx = hb[p[i]];
		}
		else
		{
			mi = hb[p[i]];
			mx = ha[p[i]];
		}
		if (mx < last)
		{
			cout << "NO";
			exit(0);
		}
		last = mi > last ? mi : mx;
	}
	cout << "YES";
	exit(0);
}