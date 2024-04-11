#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

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

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
const int N = 100 * 1000 + 5;
ld maxp[N], minp[N];

ld a[N];
ld b[N];


void gen() {
	n = 100000;
	li suma = 0, sumb = 0;
	forn (i, n) {
		a[i] = rand();
		b[i] = rand();
		suma += a[i];
		sumb += b[i];
	}
	forn (i, n) {
		a[i] /= suma;
		b[i] /= sumb;
	}
	ld sum = 0;
	{
		ld sa = 0, sb = 0;
		forn (i, n) {
			sa += a[i];
			maxp[i] = sa * b[i] + sb * a[i];
			sb += b[i];
		}
		sa = sb = 0;
		for (int i = n - 1; i >= 0; --i) {
			sb += b[i];
			minp[i] = sb * a[i] + sa * b[i];
			//a[i] = (minp[i] - sa * b[i]) / sb;
			sa += a[i];
		}
	}	
}

inline bool read() {        
//    gen();
//    return true;
    cin >> n;
    forn (i, n)
    	cin >> maxp[i];
    forn (i, n)
    	cin >> minp[i];
	return true;	
}         

void solve() {
	forn (i, n)
		a[i] = ld(1) / n;
	ld SA = 0, SB = 0;
	int ft = 0;
	while(ft < n)
	{
		ld sa = SA, sb = SB;
		pair<ld, ld> prev = mp(a[ft], b[ft]);
		for (int i = ft; i < min(n, ft + 13); ++i) {
			sa += a[i];				
			b[i] = (maxp[i] - sb * a[i]) / sa;
			sb += b[i];
		}
		sa = 1 - SA, sb = 1 - SB;
		for (int i = ft; i < min(n, ft + 13); ++i) {
			if (i == n - 1) {
				a[i] = minp[i] / b[i];
				break;
			}
			sb -= b[i];
			a[i] = (minp[i] - sa * b[i]) / sb;
			sa -= a[i];
		}
		if (fabs(prev.x - a[ft]) < EPS && fabs(prev.y - b[ft]) < EPS) {
			SA += a[ft];
			SB += b[ft];
			ft++;
		}
	}

  	forn (i, n)
		printf("%.6lf ", (double)a[i]);
	puts("");
	forn (i, n)
		printf("%.6lf ", (double)b[i]);
	
}         

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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