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

string s;

inline bool read() {
	cin >> s;
	return true;
}

int pos[26];   
char ans[2][13];

inline void solve() {   
	forn (i, 2)
		forn (j, 13)
			ans[i][j] = '.';
	forn (i, 26)
		pos[i] = -1;
	int x = 0, y = 0;
	forn (i, sz(s)) {
		int c = s[i] - 'A';
		if (pos[c] != -1) {
			x = pos[c];
			y = i;
		}	
		pos[c] = i;
	}
	
	if (x + 1 == y) {
		cout << "Impossible" << endl;
		return;
	}
	
	int cnt = y - x;
	int j = (cnt - 1) / 2;
	int id = x;
	for (int k = j; k >= 0; --k) {
		ans[1][k] = s[id++];
		cnt--;
	}
	forn (k, cnt)
		ans[0][k] = s[id++];
	
	id = (id + 1) % sz(s);
	
	for (int k = cnt; k < 13; ++k) {
		ans[0][k] = s[id];
		id = (id + 1) % sz(s);
	}
	int k = 12;
	while(ans[1][k] == '.') {
		ans[1][k] = s[id];
		id = (id + 1) % sz(s);
		k--;		
	}
	forn (i, 2) {
		forn (j, 13) {
			cout << ans[i][j];
		}
		cout << endl;
	}
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