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
const int maxn = 1e5 + 5;
int gcd(const int &a, const int &b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int asd = k;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		asd = gcd(asd, x);
	}
	cout << k / asd << endl;
	cout << 0 << " ";
	for(int i = 1; i < k / asd; i ++)
		cout << i * asd % k << " ";
	cout << endl;
	
	return 0;
}