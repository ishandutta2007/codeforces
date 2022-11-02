#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

long long n, k, p;

void solve(long long x)
{
	if (k + k == n)
	{
		if (x % 2LL == 0LL) cout << "X"; else cout << ".";
	} else
	if (k + k < n)
	{
		if (n % 2LL == 0LL)
		{
			long long length = n - 2LL * (k - 1LL);
			if (x < length)	cout << "."; else
				if (x == length) cout << "X"; else
					if ((x - length) % 2LL == 0LL) cout << "X"; else cout << ".";
		} else
		{
			long long length = n - 2LL * (k - 1LL);
			if (length == n)
			{
				if (x < length) cout << "."; else cout << "X";
			} else
			{
				length ++;
				if (x < length) cout << "."; else
					if (x == length) cout << "X"; else
						if (x == n) cout << "X"; else
							if ((x - length) % 2LL == 0LL) cout << "X"; else cout << ".";
			}
		}
	} else
	{
		long long have = n - k;
		if (x > have + have) cout << "X"; else
		{
			if (x % 2LL == 0LL) cout << "X"; else cout << ".";
		}
	}
}

long long a[1100];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k >> p;
	for (int i = 1; i <= p; i ++)
		cin >> a[i];
	for (int i = 1; i <= p; i ++)
		solve(a[i]);
	printf("\n");
	return 0;
}