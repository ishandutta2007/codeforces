#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 10100;

int N, X;
int flist[MAXN];
int nfac;

ll gcf (ll left, ll right)
{
	if (right == 0) return left;
	return gcf (right, left % right);
}

ll mpow (ll b, ll p, ll m)
{
	ll res = 1;
	
	ll p2 = b;
	for (int i = 0; i < 23; i++)
	{
		if (p & (1 << i))
			res = (res * p2) % m;
		p2 = (p2 * p2) % m;
	}
	return res;
}

bool works (int base)
{
	for (int i = 0; i < nfac; i++)
		if (mpow (base, flist[i], N+1) == 1)
			return false;
	return mpow (base, N, N+1) == 1;
	
	/*ll left = 0, right = 0;
	
	for (int i = 0; i < N; i++)
	{
		left = (base * left + 1) % N;
		right = (base * right + 1) % (N + 1);
	}
	
	ll g1 = N, g2 = N + 1;
	if (g1 % 2)
		g2 /= 2;
	else
		g1 /= 2;
	
	return gcf (right, g2) > 1;*/
}

bool prime (int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	cin >> N >> X;
	
	if (N == 1)
	{
		if (X == 2)
		{
			cout << "-1\n";
			return 0;
		}
		cout << X - 1 << "\n";
		return 0;
	}
	
	nfac = 0;
	for (int i = 1; i < N; i++)
	{
		if (N % i == 0)
		{
			flist[nfac] = i;
			nfac++;
		}
	}
	
	if (!prime (N + 1))
	{
		cout << "-1\n";
		return 0;
	}
	
	for (int i = X - 1; i >= 2; i--)
	{
		if (works (i))
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}