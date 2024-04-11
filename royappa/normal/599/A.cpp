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
	LL a, b, c;
	cin >> a >> b >> c;
	cout << min(2*a+2*b, min(2*a+2*c, min(2*b+2*c, a+b+c))) << endl;

	exit(0);
}