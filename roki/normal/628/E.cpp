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

const int N = 3005;
char c[N][N];

int n, m;

inline bool read()
{
	scanf("%d%d\n", &n, &m);
	forn (i, n)
		gets(c[i]);

	return true;
}

int l[N][N], r[N][N];
pt S[2 * N], T[2 * N];
int f[2 * N];

void inc(int pos, int d) {
	for (; pos < 2 * N; pos |= pos + 1)
		f[pos] += d;
}

int get(int pos) {
	int res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

void calc() {
	forn (i, n) {
		forn (j, m) {
			if (c[i][j] == 'z')
				l[i][j] = j ? l[i][j - 1] + 1 : 1;  
		}
	}

	forn (i, n) {
		ford (j, m) {
			if (c[i][j] == 'z')
				r[i][j] = r[i][j + 1] + 1;
		}
	}

	forn (i, 2 * N)
		S[i].x = -1;

	forn (i, n) {
		forn (j, m) {
		    if (S[i + j].x == -1)
		    	S[i + j] = mp(i, j);
			T[i + j] = mp(i, j);
		}
	}
}

queue<pt> q[N];

inline void solve() {	
	calc();

	int sum = 0;

	li ans = 0;

	forn (i, 2 * N) {
		if (S[i].x == -1)
			continue;
		int x = S[i].x, y = S[i].y;
		while (x <= T[i].x) {
			if (c[x][y] != 'z') {
				x++, y--;
				continue;
			}	
			int nx = x, ny = y;
			while (nx <= T[i].x && c[nx][ny] == 'z') { 	
				int lvl = max(0, nx - x - r[nx][ny] + 1);
				q[lvl].push(mp(nx, ny));	
			 	nx++, ny--;
			}
			nx = x, ny = y;
			while (nx <= T[i].x && c[nx][ny] == 'z') { 	
				while (!q[nx - x].empty()) {
					pt v = q[nx - x].front();
					inc(v.x, +1);
					sum++;
					q[nx - x].pop();
				}
				ans += get(l[nx][ny] + nx - 1);
				inc(nx, -1);
				sum--;
				nx++, ny--;
			}
			x = nx, y = ny;
		}
		cerr << ans << endl;
	}
	cout << ans << endl;
}

int main()
{


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