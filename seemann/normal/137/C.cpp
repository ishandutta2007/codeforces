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

struct event{
	int x;
	int n;
	bool type;
};

bool operator < (event a, event b)
{
	return a.x < b.x;
}

event a[200002];
int st[200002];
bool use[200002];
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n;
	cin >> n;
	FOR(i, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[2 * i].x = x;
		a[2 * i].type = true;
		a[2 * i].n = i;
		a[2 * i + 1].x = y;
		a[2 * i + 1].type = false;
		a[2 * i + 1].n = i;
	}
	sort(a, a + 2 * n);
	n = 2 * n;
	int p1 = 0, p2 = 0;
	while (!a[p1].type)
		p1++;
	while (a[p2].type)
		p2++;
	clr(use);
	int ans = 0;
	while (p2 < n)
	{
//		cerr << p1 << ' ' << p2 <<'\n';
		while ((!a[p1].type) || (use[a[p1].n]))
			p1++;
		while (a[p2].type)
			p2++;
		if (a[p1].n != a[p2].n)
			ans++;
		use[a[p2].n] = true;
		p2++;
	}
	
	cout << ans;
	return 0;
}