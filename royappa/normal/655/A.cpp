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
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	reverse(b.begin(), b.end());
	reverse(d.begin(), d.end());
	string x = a+b, y = c+d;
	auto p = x.find('X');
	x.erase(x.begin()+p, x.begin()+p+1);
	p = y.find('X');
	y.erase(y.begin()+p, y.begin()+p+1);
	if ((x+x).find(y) != -1)
	{
		cout << "YES" << endl;
		exit(0);
	}
	cout << "NO" << endl;
	exit(0);
}