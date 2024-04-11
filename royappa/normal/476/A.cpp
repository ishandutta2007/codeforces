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


//http://codeforces.com/contest/476/problem/0



using namespace std;


typedef long long LL;



int main()
{
	int n, m;
	cin >> n >> m;
	// minimize a+b such that
	// a+2*b = n
	// (a+2*b)%m == 0
	int best = -1;
	for (int a = 0; a <= n; a++)
	{
		if ((n-a)%2 != 0)
			continue;
		int b = (n-a)/2;
		if ((a+b)%m != 0)
			continue;
		if (best == -1 || a+b < best)
		{
			best = a+b;
		}
	}
	cout << (best == -1 ? -1 : best) << endl;

	exit(0);
}