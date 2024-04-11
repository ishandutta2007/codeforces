#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

ll next (ll a)
{
	ll w = a;
	ll st = 1;
	bool ind = false;
	while(w / st > 0)
	{
		if ((w / st % 10) == 4)
		{
			w += st * 3;
			ind = true;
			break;
		}
		else
			w -= st * 3;
		
		st *= 10;
	}
	if (!ind)
		w += st * 4;
	return w;
}

bool good (ll a)
{
	ll w = a;
	ll st = 1;
	while(w / st > 0)
	{
		if ((w / st) % 10 != 4 && (w / st) % 10 != 7)
			return false;
		st *= 10;
	}
	return true;
}

ll a[100];
vector <int> b;



int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	ll n, k;
	cin >> n >> k;
	ll m = 1;
	ll nm = 1;
	while (nm < k)
	{
		m++;
		nm *= m;
	}
	if (m > n)
	{
		printf("-1");
		return 0;
	}
	ll ans = 0;
	ll w = 4;
	while (w <= n - m)
	{
		w = next(w);
		ans++;
	}
	for (int i = n - m + 1; i <= n; ++i)
		b.push_back(i);
	ll ft = n - m + 1;
	k--;

	FOR(i, m)
	{
		nm /= (m - i);
	//	cerr << b[k / nm] << ' ' << ft + i << '\n';
		if (good(b[k / nm]) && good(ft + i))
			ans++;
		b.erase(b.begin() + k / nm);
		k %= nm;
	}	
	cout << ans;



	return 0;
}