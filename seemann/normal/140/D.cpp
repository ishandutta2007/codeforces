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
const int MAXN = 102;

int a[MAXN];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
		cin >> a[i];
	sort(a, a + n);
	int t = 0;
	int ct = 0;
	int c = 0;
	FOR(i, n)
	{
		t += a[i];
		if (t > 710)
			break;
		c++;
		if (t > 350)
			ct += t - 350;
	}
	cout << c << ' ' << ct;
	return 0;
}