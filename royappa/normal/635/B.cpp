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

#include <algorithm>

using namespace std;



int main()
{
	int n;
	vector<int> a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x != 0) a.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x != 0) b.push_back(x);
	}
	n--;
	int x = a[0];
	int posb = -1;
	for (int i = 0; i < n; i++)
	{
		if (b[i] == x)
		{
			posb = i;
			break;
		}
	}
	int eq = 0;
	int posa = 0;
	while (b[posb] == a[posa] && eq < n)
	{
		posa = (posa+1)%n;
		posb = (posb+1)%n;
		eq++;
	}
	cout << ((eq == n) ? "YES" : "NO") << endl;
}