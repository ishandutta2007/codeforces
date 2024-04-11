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

int main()
{
	int n;
	cin >> n;
	vector<LL> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	LL delta = 0;
	LL steps = 0;
	for (int i = 0; i < n; i++)
	{
		steps += abs(v[i]-delta);
		delta += v[i]-delta;
	}
	cout << steps << endl;

	exit(0);
}