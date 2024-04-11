#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int y, b, r;
	cin >> y >> b >> r;
	r -= 2;
	b -= 1;
	cout << 3 * min(y, min(b, r)) + 3 << endl;
	
	return 0;
}