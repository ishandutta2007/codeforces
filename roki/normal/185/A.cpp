#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int mod = 1e9 + 7;
li c;

bool read()
{
	cin >> c;
	return true;
}

li bp(li a, li b)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return a * bp(a, b - 1) % mod;
	return bp(a * a % mod, b >> 1);
}

li f(li a)
{
	return (a * (a + 1) % mod) * bp(2, mod - 2) % mod;
}

void solve()    
{
	cout << f(bp(2, c));
}

int main()
{
#ifdef Baster
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}