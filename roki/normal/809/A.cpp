#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <queue>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <bitset>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

const int N = 300 * 1000 + 5;
int a[N];

int n;

inline bool read() {
	cin >> n;
	forn(i, n)
		cin >> a[i];
	return true;
}

int d2[N];

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return li(a) * b % MOD;
}

inline void solve() {	
	sort(a, a + n);
	int ans = 0;
	d2[0] = 1;
	
	for (int i = 1; i < N; ++i)
		d2[i] = mul(d2[i - 1], 2);

	forn(i, n) {
		int d = n - 1 - i - 1;
		int cnt = d2[d + 1] - 1;
		ans = (ans + mul(cnt, MOD - a[i])) % MOD;
		
		d = i - 0 - 1;
		cnt = d2[d + 1] - 1;
		ans = (ans + mul(cnt, a[i])) % MOD;
	}
	cout << ans << endl;
}

int main()
{

#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	read();
	solve();
	
#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}