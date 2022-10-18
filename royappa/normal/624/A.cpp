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
	int d, L, v1, v2;
	cin >> d >> L >> v1 >> v2;
	printf("%.6lf\n", double(L-d)/double(v1+v2));
	exit(0);
}