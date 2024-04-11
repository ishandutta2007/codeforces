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


//http://codeforces.com/contest/472/problem/B

using namespace std;


typedef long long LL;

bool isPrime(int x)
{
	if (x == 1)
		return false;
	if (x == 2 || x == 3)
		return true;
	for (int d = 2; d*d <= x; d++)
	{
		if (x%d == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int x = 2; x <= n-2; x++)
	{
		if (!(isPrime(x) || isPrime(n-x)))
		{
			cout << x << " " << n-x << endl;
			exit(0);
		}
	}
	exit(0);
}