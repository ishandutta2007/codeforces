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

int n, k;
const int N = 100 * 1000 + 5;
char s[N];
char ans[N];

inline bool read()
{
	scanf("%d%d\n", &n, &k);
	gets(s);
	return true;
}

inline void solve()
{
	forn (i, n) {
		int md = max('z' - s[i], s[i] - 'a');
		if (md < k) {
			k -= md;
			if ('z' - s[i] > s[i] - 'a')
				ans[i] = 'z';
			else
				ans[i] = 'a';
		} else {
			if (s[i] + k <= 'z')
				ans[i] = s[i] + k;
			else
				ans[i] = s[i] - k;
			k = 0;
		}
	}

	if (k)
		puts("-1");
	else
		printf("%s\n", ans);
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