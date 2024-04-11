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

using namespace std;

int memo[1001];

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	int n;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	cin >> n;

	int cs = (a1+a2+a3+4)/5;
	int ms = (b1+b2+b3+9)/10;
	cout << ((cs+ms <= n) ? "YES\n" : "NO\n");
}