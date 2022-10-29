#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define ft first
#define sc second
#define x first
#define y second
#define mp make_pair
#define pb push_back

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

string s;

inline bool read()
{
	cin >> s;
	return true;
}

inline void solve()
{
	li ans = 0;
	forn (i, sz(s)) {
		if (s[i] == '0' || s[i] == '4' || s[i] == '8')
			ans++;
	}

	forn (i, sz(s) - 1) {
		int temp = (s[i] - '0') * 10 + s[i + 1] - '0';
		if (temp % 4 == 0)
			ans += i + 1;
	}

	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;
	
	srand(time(NULL));
	
	read();
	solve();
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif
	
	return 0;
}