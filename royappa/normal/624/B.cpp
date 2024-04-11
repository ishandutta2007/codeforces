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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.rbegin(), v.rend());
	for (int j = 1; j < n; j++)
	{
		v[j] = max(0, min(v[j-1]-1, v[j]));
	}
	cout << accumulate(v.begin(), v.end(), 0LL) << endl;
	exit(0);
}