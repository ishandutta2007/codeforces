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
const long long mod = 1e9 + 7;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long now1 = 1, now2 = 1;
	for(int i = 1; i <= n; i ++)
		(now1 *= i) %= mod;
	for(int i = 1; i < n; i ++)
		(now2 *= 2) %= mod;
	cout << (now1 + mod - now2) % mod << endl;
	
	return 0;
}