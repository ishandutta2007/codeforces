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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	ll a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	ll nx1 = (x1 + y1) / (2 * a);
	if (x1 + y1 < 0)
		nx1--;
	ll ny1 = (x1 - y1) / (2 * b);
	if (x1 - y1 < 0)
		ny1--;
	ll nx2 = (x2 + y2) / (2 * a);
	if (x2 + y2 < 0)
		nx2--;
	ll ny2 = (x2 - y2) / (2 * b);
	if (x2 - y2 < 0)
		ny2--;
	ll dx = abs(nx1 - nx2);
	ll dy = abs(ny1 - ny2);
	ll ans = max(dx, dy);
	cout << ans;
	return 0;
}