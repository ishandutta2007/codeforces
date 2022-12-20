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
	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	long long n1 = n / m * m, n2 = n1 + m;
	cout << min((n - n1) * b, (n2 - n) * a) << endl;
	
	return 0;
}