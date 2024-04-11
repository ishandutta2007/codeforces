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

const int inf = (int)1e9 + 7, nmax = (int)1e2 + 10, temp = 0;
const double eps = 1e-9;

long long ans;
int n, a[nmax][nmax], T[nmax], t[4 * nmax], c[nmax], k, l, m, r, x, y, z, len;
vector < int > g[nmax];
string s, u, v[nmax];
char buf[65];


int main()
{	
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)	
			cin >> a[i][j];
	
	int r = a[0][0] % k;
	bool fl = true;
	x = z = inf;
	y = -inf;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			if(a[i][j] % k != r)
				fl = false;
			x = min(x, a[i][j]);
			y = max(y, a[i][j]);
		}
	
	if(fl == true)
	{
		for(int i = x; i <= y; i += k)
		{
			int tmp = 0;
			for(int j = 0; j < n; ++j)
				for(int l = 0; l < m; ++l)
					tmp += abs(a[j][l] - i) / k;
			z = min(z, tmp);
		}
	}
	
	if(fl)
		cout << z << endl;
	else
		cout << -1 << endl;
		
	return 0;
}