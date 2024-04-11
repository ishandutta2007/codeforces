#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	int res = 0;
	for (int i = 1; i <= d; i++)
		if (i % k && i % l && i % m && i % n)
			res++;
	cout << d - res << "\n";
}