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

int n, q;

const int N = 200 * 1000 + 5;
string s;
int a[N];

inline bool read() {
	cin >> n >> q;
	cin >> s;
	forn (i, n)
		a[i] = s[i] - '0';
	return true;
}

int t[4 * N][5][5];

int d[10];

void upd(int &a, int b) {
	a = min(a, b);
}

void calc(int a[5][5], int b[5][5], int c[5][5]) {
	forn (i, 5)
		forn (j, 5)
			a[i][j] = INF;	

	forn (i, 5)
		forn (j, 5)
			for (int jj = 0; i + j + jj < 5; ++jj)
				upd(a[i][j + jj], b[i][j] + c[i + j][jj]);
}

void build(int id, int l, int r) {
	forn (i, 5) 
		forn (j, 5)
			t[id][i][j] = INF;
	if (l + 1 == r) {
		forn (i, 5) {
			t[id][i][0] = i == d[a[l]];
			if (i == d[a[l]])
				t[id][i][1] = 0;
		}
		if (a[l] == 6)
			for (int i = 3; i < 5; ++i)
				t[id][i][0] = 1;
		return;	
	}
	int mid = (l + r) / 2;
	build(2 * id + 1, l, mid);
	build(2 * id + 2, mid, r);
	calc(t[id], t[2 * id + 1], t[2 * id + 2]);
}
   
void get(int id, int l, int r, int lq, int rq, int cur[5][5]) {
	if (l == lq && r == rq) {
		int tmp[5][5];
		calc(tmp, cur, t[id]);
		forn (i, 5)
			forn (j, 5)
				cur[i][j] = tmp[i][j];
		return;
	}
	int mid = (l + r) / 2;
	if (lq < mid)
		get(2 * id + 1, l, mid, lq, min(mid, rq), cur);
	if (rq > mid)
		get(2 * id + 2, mid, r, max(mid, lq), rq, cur);
}

inline void solve() {   
	memset(d, -1, sizeof d);
	d[2] = 0, d[0] = 1, d[1] = 2, d[7] = 3;
	build(0, 0, n);
	forn (it, q) {
		int l, r;
		cin >> l >> r;
		l--;
		int cur[5][5];
		forn (i, 5)
			forn (j, 5)
				cur[i][j] = j ? INF : 0;
		get(0, 0, n, l, r, cur);
		if (cur[0][4] > INF / 2)
			cur[0][4] = -1;
		cout << cur[0][4] << endl;
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