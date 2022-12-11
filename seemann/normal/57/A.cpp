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

int _gt(int n, int x, int y)
{
	if (y == 0)
		return x;
	if (x == n)
		return y + n;
	if (y == n) return 3 * n - x;
	if (x == 0) return 4 * n - y;

}

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	int a1 = _gt(n,x1, y1);	
	int a2 = _gt(n, x2, y2);
	cout <<min(abs(a2 - a1), 4 * n - max(a2, a1) + min(a1, a2));
	return 0;
}