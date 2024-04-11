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



int main()
{
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	int minx = *min_element(x.begin(), x.end());
	int maxx = *max_element(x.begin(), x.end());
	int miny = *min_element(y.begin(), y.end());
	int maxy = *max_element(y.begin(), y.end());
	int a = (maxx-minx)*(maxy-miny);
	cout << (a > 0 ? a : -1) << endl;

	exit(0);
}