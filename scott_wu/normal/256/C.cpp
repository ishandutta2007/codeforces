#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int P = (1 << 20);
const int NDIG = 20;
const int MAXP = 2 * P + 100;
const int MAXS = 11;
const int MAXN = 100100;

int N;
ll arr[MAXN];
int mval[MAXN];
int seg[MAXS][MAXP];

ll msq (ll x)
{
	ll lo = 0, hi = 1e7;
	while (lo < hi)
	{
		ll mid = (lo + hi + 1) / 2;
		if (mid * mid <= x)
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

ll mqu (ll x)
{
	ll lo = 0, hi = 1e4;
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (mid * mid * mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

void upd (int nseg, int loc)
{
	loc += P;
	
	while (loc > 0)
	{
		seg[nseg][loc]++;
		loc /= 2;
	}
}

int sum (int nseg, int loc)
{
	int ans = 0, cur = 1;
	for (int i = NDIG - 1; i >= 0; i--)
	{
		if (loc & (1 << i))
		{
			ans += seg[nseg][2*cur];
			cur = 2 * cur + 1;
		}
		else
			cur = 2 * cur;
	}
	return ans;
}

int solve (ll x)
{
	ll lo = mqu (x), hi = msq (x);
	for (int i = 0; i < MAXS; i++)
	{
		int res = sum (i, hi + 1) - sum (i, lo);
		if (res == 0)
			return i;
	}
	return MAXS - 1;
}

int main()
{
	for (int i = 0; i < MAXS; i++)
		for (int j = 0; j < MAXP; j++)
			seg[i][j] = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	upd (0, 1);
	for (int i = 2; i <= 1000000; i++)
	{
		int rloc = solve (i);
		upd (rloc, i);
		//if (i <= 20) cout << i << " " << rloc << "\n";
	}
	
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > (ll) 1)
			x ^= solve (arr[i]);
	}
	
	if (x > 0)
		cout << "Furlo\n";
	else
		cout << "Rublo\n";
	return 0;
}