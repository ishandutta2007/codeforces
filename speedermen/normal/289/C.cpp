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
	cin >> n >> k;
	if(n < k || (k == 1 && n != 1))
		cout << - 1 << endl;
	else 
	{
		if(n == k)
		{
			char c = 'a' - 1;
			for(int i = 0; i < n; ++i)
				s += char(++c);
		}
		else
		{
			for(int i = 0; i < n - k + 2; ++i)
				s += (i % 2 ? "b" : "a");
			char c = 'b';
			for(int i = n - k + 2; i < n; ++i)
				s += char(++c);
		}
		cout << s << endl;
	}
	
	return 0;
}