#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define msn(a, v, n) memset(a, v, n * sizeof(a[0]))
#define mcp(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define x first
#define y second

#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))

template<typename T> T sqr(const T &x) {
	return x * x;
}

template<typename T> T my_abs(const T &x) {
	return x < 0 ? -x : x;
}

typedef long long li;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<li,li> pli;
typedef pair<ld,ld> pd;

const int INF = (int)1e9;
const li INF64 = (li)4e18;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

string s;
const int N = 105;
string t[N];
int n;

bool read() {
	cin >> s;
	cin >> n;
	forn (i, n)	
		cin >> t[i];
    return true;
}

void solve() {
	set<string> sc;
	forn (i, n)
		sc.insert(t[i]);
	forn (mask, 4) {
		forn (i, 26)
			forn (j, 26) {
				string p = s;
				if (mask & 1) {
					p = char('a' + i) + p;
				}
				if (mask & 2) {
					p = p + char('a' + j);
				}
				if (sz(p) % 2)
					continue;
				bool ok = true;
				for (int pos = 0; pos < sz(p); pos += 2) {
					string cur = "";
					forn (j, 2)
						if (pos + j < sz(p))
							cur += p[pos + j];
					ok &= sc.count(cur);
	//				cerr << cur << ' ';
				}
	//			cerr << endl;
				if (ok) {
					cout << "YES" << endl;
					cerr << p << endl;
					return;
				}
			}
	}
	cout << "NO" << endl;
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#ifdef FILES	
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
#endif
	
	srand((unsigned int)time(NULL));

	cout << setprecision(15) << fixed;

	read();
	solve();
	
#ifdef _DEBUG
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}