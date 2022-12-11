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
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int m, n;
	cin >> n >> m;
	int l, r;
	l = 0;
	r = n + 1;
	FOR(i, m)
	{
		int w;
		string ws;
		cin >> ws;
		cin >> ws;
		cin >> ws;
		bool ind = false;
		if (ws[0] == 'l') ind = true;
		cin >> ws;
		cin >> w;
		if (ind) r = min(r, w);
			else l = max(l, w);
	}
	if (r <= l + 1) cout << -1;
		else cout << (r - l - 1);

	return 0;
}