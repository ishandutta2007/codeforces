#include <bits/stdc++.h>

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

int n, m;
const int N = 25;
int a[N][N];

inline bool read() {
	cin >> n >> m;
	forn (i, n)
		forn (j, m) 
			cin >> a[i][j];
	return true;
}
   
int b[N][N];

inline void solve() {   
	forn (i, n)
		forn (j, m)
			a[i][j]--;	

	forn (j1, m)
		forn (j2, j1 + 1) {

			forn (i, n)
				forn (j, m)
					b[i][j] = a[i][j];
			
			bool ok = true;

			forn (i, n) {
				swap(b[i][j1], b[i][j2]);
				int cnt = 0;
				forn (j, m)
					cnt += b[i][j] != j;
				
				if (cnt <= 2) {
					if (j1 != j2)
					continue;
				}
			
				swap(b[i][j1], b[i][j2]);
				
				int sw = 1;
				if (b[i][j1] != j2) {
					forn (j, m)
						if (b[i][j] == j2) {
							swap(b[i][j], b[i][j1]);
							sw--;
						}
				}
				if (b[i][j2] != j1) {
					forn (j, m)
						if (b[i][j] == j1) {
							swap(b[i][j], b[i][j2]);
							sw--;
						}
				}
				swap(b[i][j1], b[i][j2]);
				cnt = 0;
				forn (j, m)
					if (b[i][j] != j)
						cnt++;
				if (sw < 0)
					ok = false;
				if (sw == 0)
					ok &= cnt == 0;
				if (sw == 1)
					ok &= cnt <= 2;
			}
			if (ok) {
				cout << "YES" << endl;
				cerr << j1 + 1 << ' ' << j2 + 1 << endl;
				return;
			}
		}
	cout << "NO" << endl;
}

int main()
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}