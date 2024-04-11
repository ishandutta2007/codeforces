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

const int N = 205;
string s[N];
int n;

bool read() {
    cin >> n;
    forn (i, n)
    	cin >> s[i];
    
    return true;
}

const int M = 14;

pair<string, string> p[N];
bitset<1 << M> msk[N][M];
bool split[N];


void merge(int a, int b) {
	if (!split[a])
		p[n].x = p[a].x + p[b].x;
	else
		p[n].x = p[a].x;
	if (!split[b])
		p[n].y = p[a].y + p[b].x;
	else
		p[n].y = p[b].y;
	split[n] = split[a] | split[b];
	if (sz(p[n].x) > M)
		p[n].x.resize(M), split[n] = true;
	if (sz(p[n].y) > M) {
		reverse(all(p[n].y));
		p[n].y.resize(M);
		reverse(all(p[n].y));
		split[n] = true;
	}
	
	forn (i, M)
		msk[n][i] = msk[a][i] | msk[b][i];
	
	//cerr << msk[n][1].count() << endl;
		
	string mid = p[a].y + p[b].x;
//	cerr << mid << endl;
	forn (len, M) {
		forn (pos, sz(mid) - len) {
			string cc = "";
			int cmask = 0;
			forn (k, len + 1) {
				cc += mid[pos + k];
				cmask = cmask * 2 + (mid[pos + k] - '0');
			}
			msk[n][len][cmask] = true;
			//cerr << cc << ' ';
		}
	//	cerr << endl;
	}
	int cans = 0;
	forn (len, M) {
	//	cerr << msk[n][len].count() << ' ' << len + 1 << endl;
		if (msk[n][len].count() == (2 << len)) {
			cans = len + 1;
		} 
	}
	cout << cans << endl;
	n++;
}

void solve() {
	forn (i, n) {
		p[i].x = p[i].y = s[i];
	//	cerr << "STR " + s[i] << endl;
		forn (j, M) { 
			forn (pos, sz(s[i]) - j) {
				int cmask = 0;
				string cc;
				forn (k, j + 1) {
					cmask = cmask * 2 + (s[i][pos + k] - '0');
					cc += s[i][pos + k];
				}
				//cerr << cc << endl;
				msk[i][j][cmask] = true;
			}	
		}
	//	cerr << endl;
	}
	int m;
	cin >> m;
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		merge(a, b);
	}
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