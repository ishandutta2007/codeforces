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

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	ll l, r;
	cin >> l >> r;
	ll w = 4;
	while (w < l)
		w = next(w);
	ll ans = 0;
	ll last = l;
	ans = w;
	while (w < r)
	{
		ans += (w - last) * w;
		last = w;
		w = next(w);
	}
	ans += (r - last) * w;
	cout << ans;


	return 0;
}