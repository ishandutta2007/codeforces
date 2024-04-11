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

#include <queue>

using namespace std;


typedef long long LL;

int main()
{
	LL n, k;

	cin >> n >> k;
	LL mess = 0;
	LL t = min(k, n/2);
	for (LL i = 1; i <= t; i++)
	{
		mess += n-i+1-1;
		mess += (n-i+1)-(t+1)+1-1;

	}

	cout << mess << endl;
	exit(0);
}