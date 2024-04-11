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

int p[501];
int x[501];

int main()
{
	//freopen("", "r", stdin);
//	freopen("g.in", "w", stdout);
	//freopen("", "w", stderr);
	int n = 323;
	x[0] = 0;
	p[0] = 100000;
	x[1] = 1324;
	p[1] = 324;
	for (int i = 2; i < n - 1; ++i) {
		p[i] = p[i - 1] - 1;
		x[i] = x[i - 1] + p[i - 1] + p[i];
	}
	p[n - 1] = 1000000;
	x[n - 1] = 500000;
	cout<< n << '\n';
	FOR(i, n) {
		cout << x[i] << ' ' << p[i] << '\n';
	}



	
	return 0;
}