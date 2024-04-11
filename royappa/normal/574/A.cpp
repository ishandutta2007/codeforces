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
	{
		cin >> v[i];
	}
	int res = 0;
	while (true)
	{
		int p = -1;
		for (int i = 1; i < n; i++)
		{
			if (v[i] >= v[0] && (p == -1 || v[i] > v[p]))
			{
				p = i;
			}
		}
		if (p == -1)
			break;
		v[p]--;
		v[0]++;
		res++;
	}
	cout << res << endl;

}