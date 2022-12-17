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
	long long n, k;
	cin >> n >> k;
	cout << (2 * n - 1) / k + 1 + (5 * n - 1) / k + 1 + (8 * n - 1) / k + 1 << endl;
	
	return 0;
}