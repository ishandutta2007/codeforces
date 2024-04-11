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


typedef unsigned int LL;

typedef pair<LL,LL> pLL;

// This works in roughly O(sqrt(n)). It is NOT efficient for LL types (10^18) but good enough for unsigned int (4*10^9)
// This is just using LL to avoid using unsigned int.
// CHECK the maximum sqrt(n) value before using // LOOKS WRONG because sieve[] is never set??
vector<pLL> uniquePrimeFactorization(LL n)
{
	while (n%2 == 0)
		n /= 2;
	while (n%3 == 0)
		n /= 3;
	LL s = LL(ceil(sqrt(double(n))))+1;
	vector<int> sieve(s, 1);
	for (LL i = 2; i < s; i++)
	{
		if (sieve[i])
		{
			LL q = i*i;
			while (q < s)
			{
				sieve[q] = 0;
				q += i;
			}
		}
	}
	// now "sieve" will tell us all primes up to sqrt(n)
	vector<pLL> res;
	for (LL p = 2; p < s; p++)
	{
		if (sieve[p] && n % p == 0) // p is prime divisor of n
		{
			int pe = 0;
			while (n % p == 0)
			{
				n /= p;
				pe++;
			}
			res.push_back(make_pair(p, pe));
		}
	}
	if (n > 1) // there could be one prime left that is larger than sqrt(n)
	{
		res.push_back(make_pair(n, 1));
	}
	return res;
}

int main()
{
	int n;

	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	vector<pLL> factors = uniquePrimeFactorization(v[0]);
	for (int i = 1; i < n; i++)
	{
		int num = v[i];
		while (num%2 == 0) num /= 2;
		while (num%3 == 0) num /= 3;
		for (int i = 0; i < factors.size(); i++)
		{
			int f = factors[i].first, e = factors[i].second;
			int e2 = 0;
			while (num%f == 0)
			{
				num /= f;
				e2++;
			}
			if (e2 != e)
			{
				cout << "No" << endl;
				exit(0);
			}
		}
		if (num > 1)
		{
			cout << "No" << endl;
			exit(0);
		}
	}

	cout << "Yes" << endl;
	exit(0);
}