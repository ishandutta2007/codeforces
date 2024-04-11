#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

int n;

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;

	return true;
}

const int MOD = 1000 * 1000 * 1000 + 7;

inline int binPow (int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * 1ll * a) % MOD;
			
		b >>= 1;
		a = (a * 1ll * a) % MOD;
	}
	
	return ans;
}

inline int rev (int a)
{
	return binPow(a, MOD - 2);
}

inline int f (int n)
{
	int ans = 1;
	fore (i, 1, n)
		ans = (ans * 1ll * i) % MOD;
		
	return ans;
}

//2*(2*n-1)!/(n!*(n-1)!)-1.

inline void solve()
{
	n++;

	int ans = (2 * f(2 * n - 1)) % MOD;
	ans = (ans * 1ll * rev(f(n))) % MOD;
	ans = (ans * 1ll * rev(f(n - 1))) % MOD;	
	
	ans = (ans - 1 + MOD) % MOD;
	
	cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}