#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	ll n, k;
	int p;
	cin >> n >> k;
	cin >> p;

	FOR(i, p)
	{
		ll w;
		cin >> w;
		w--;
		if (k == 0) {cout << '.';continue;}
		if (k <= n / 2)
		{
			if (n % 2 == 1 && w == n - 1)
			{
				cout << 'X';
				continue;
			}
			ll wn = n;
			ll wk = k;
			if (n % 2 == 1) wn--, wk--;
			if (w % 2 == 0)
				cout << '.';
			else
				if (w >= wn - 2 * wk + 1) cout << 'X';
				else
					cout << '.';
		}
		else
		{
			if (w % 2 == 1)
				cout << 'X';
			else
				if (w >= (n - k) * 2 - 1) cout << 'X';
				else
					cout << '.';
		}
	}
	return 0;
}