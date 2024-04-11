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

int n, m, q;
const int N = 105;
int a[N][N];
vector<int> b[N * N];
            
inline bool read() {        
	cin >> n >> m >> q;
	int x;         
	forn (i, q) {
		int t;
		cin >> t;
		b[i].pb(t);
		int x, y, z;
		cin >> x;
		b[i].pb(x);
		if (t == 3) {
			cin >> y >> z;
			b[i].pb(y);
			b[i].pb(z);
		}
	}
	return true;	
}

void shiftline(int i) {
	int x = a[i][m - 1];
	for (int j = m - 1; j > 0; --j)
		a[i][j] = a[i][j - 1];
	a[i][0] = x;	
}

void shiftrow(int j) {
	int x = a[n - 1][j];
	for (int i = n - 1; i > 0; --i)
		a[i][j] = a[i - 1][j];
	a[0][j] = x;	
}            

void solve() {
    cerr << n << ' ' << m << endl;
	
	for (int i = q - 1; i >= 0; --i) {
		int t = b[i][0];
		if (t == 1) 
			shiftline(b[i][1] - 1);
		if (t == 2)
			shiftrow(b[i][1] - 1);
		if (t == 3) {
			a[b[i][1] - 1][b[i][2] - 1] = b[i][3];
		}
	}
	forn (i, n) {
		forn (j, m)
			cout << a[i][j] << ' ';
		cout << endl;
	}         
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