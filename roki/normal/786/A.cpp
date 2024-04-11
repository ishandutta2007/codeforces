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

int n;
const int N = 7005;
vector<int> a[2];

inline bool read() {
	cin >> n;
	forn (i, 2) {
		int k;
		cin >> k;
		a[i].resize(k);
		forn (j, k)
			cin >> a[i][j];
	}
	return true;
}
   
int dp[N][2];
bool used[N][2];
int cnt[N][2];

inline void solve() {   
	
	
	memset(dp, -1, sizeof dp);

	dp[0][0] = dp[0][1] = 0;

	forn (i, n)
		forn (j, 2)
			cnt[i][j] = sz(a[j]);
	
	queue<pt> q;
	q.push(mp(0, 0));
	q.push(mp(0, 1));
	used[0][0] = used[0][1] = true;
	
	while(!q.empty()) {
		int v = q.front().x;
		int p = q.front().y;
		q.pop();
		int np = p ^ 1;
		for (int x : a[np]) {
			int nv = ((v - x) % n + n) % n;
			if (used[nv][np])
				continue;
			if (dp[v][p] == 0) {
				dp[nv][np] = 1;
				q.push(mp(nv, np));
				used[nv][np] = true;
			}
			if (dp[v][p] == 1) {
				cnt[nv][np]--;
				if (cnt[nv][np] == 0) {
					dp[nv][np] = 0;
					q.push(mp(nv, np));
					used[nv][np] = true;
				}
			}
		}
	}
	forn (j, 2) {
		forn (i, n) {
			if (i == 0)
				continue;
			if (dp[i][j] == 0)
				cout << "Lose ";
			if (dp[i][j] == 1)
				cout << "Win ";
			if (dp[i][j] == -1)
				cout << "Loop ";
		}
		cout << endl;
	}
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}