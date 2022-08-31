#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

ll solve (ll x, ll y)
{
	if (x < y) swap (x, y);
	if (y == 0) return 0;
	return x / y + solve (y, x % y);
}

int main()
{
	ll A, B;
	cin >> A >> B;
	
	cout << solve (A, B) << "\n";
	return 0;
}