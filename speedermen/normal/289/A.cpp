#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define s second
#define f first

const int inf = (int)1e9 + 7, nmax = (int)1e5 + 10, temp = 0;
const double eps = 1e-9;

long long ans;
int n, a[nmax], T[nmax], t[4 * nmax], c[nmax], k, l, m, r, x, y, z, len;
vector < int > g[nmax];
string s, u, v[nmax];
char buf[65];


int main()
{	
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i] >> c[i];
		ans += c[i] - a[i] + 1;
	}
	
	cout << (k - ans % k) % k << endl;
	
	return 0;
}