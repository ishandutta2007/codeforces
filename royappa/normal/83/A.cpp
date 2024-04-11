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
#include <queue>

using namespace std;
int debug = 0;


typedef long long LL;
int main()
{
	int n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int p = 0;
	LL r = 0;
	LL len;
	for (int i = 0; i < n; i++)
	{
		if (v[i] != v[p])
		{
			len = (i-1)-p+1;
			r += len*(len+1)/2;
			p = i;
		}
	}
	len = (n-1)-p+1;
	r += len*(len+1)/2;
	cout << r << endl;
}