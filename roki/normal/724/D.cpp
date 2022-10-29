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

const int N = 100 * 1000 + 5;
int a[N];
int m;
string s;

inline bool read() {
	cin >> m >> s;
	return true;
}
   
bool ok() {
	int bal = 0;
	forn (i, m)
		bal += a[i];
	forn (i, sz(s) - m + 1) {
	//	cerr << bal << endl;
		if (bal == 0)
			return false;
		bal += a[i + m] - a[i];
	}
	return true;
}

inline void solve() {

	string ans = "";	

	forn (it, 26) {
		char c = 'a' + it;
		memset(a, 0, sizeof a);
		forn (i, sz(s))
			a[i] = s[i] <= c;
		if (!ok())
			continue;
		memset(a, 0, sizeof a);
		vector<int> pos;
		forn (i, sz(s)) {
			a[i] = s[i] < c;
			if (s[i] < c)
				ans += s[i];
			if (s[i] == c)
				pos.pb(i);	
		}		
		sort(all(ans));

		int bal = 0;
		forn (i, m)
			bal += a[i];
		forn (i, sz(s) - m + 1) {
			if (bal == 0) {
				bal++;
				int j = lower_bound(all(pos), i + m) - pos.begin() - 1;
				assert(pos[j] >= i && pos[j] < i + m);
				a[pos[j]] = 1;
				ans += c;
			}
			bal += a[i + m] - a[i];
		}
		cout << ans << endl;
		return;
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