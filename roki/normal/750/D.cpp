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

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 500;
bool ans[N][N];

bool used[N][N][34][8];

int n;
int d[34];

inline bool read() {
	cin >> n;
	forn (i, n)
		cin >> d[i];
	return true;
}

struct st{
	int x, y, t, dir;
};

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
   
inline void solve() {
	queue<st> q;   
	st s = {250, 250, 0, 0};
	q.push(s);
	used[250][250][0][0] = true;
	while(!q.empty()) {
		st v = q.front();
		if (v.t == n)
			break;
		q.pop();
		forn (i, d[v.t])
			ans[v.x + dx[v.dir] * i][v.y + dy[v.dir] * i] = true;
		v.x += dx[v.dir] * (d[v.t] - 1), v.y += dy[v.dir] * (d[v.t] - 1);
		int next = (v.dir + 1) % 8;
		int prev = (v.dir + 7) % 8;
		st v1 = {v.x + dx[next], v.y + dy[next], v.t + 1, next};
		st v2 = {v.x + dx[prev], v.y + dy[prev], v.t + 1, prev};
		if (!used[v1.x][v1.y][v1.t][v1.dir]) {
			used[v1.x][v1.y][v1.t][v1.dir] = true;
			q.push(v1);
		}
		if (!used[v2.x][v2.y][v2.t][v2.dir]) {
			used[v2.x][v2.y][v2.t][v2.dir] = true;
			q.push(v2);
		}
	}
	int res = 0;
	forn (i, N)
		forn (j, N)
			res += ans[i][j];
	cout << res << endl;
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