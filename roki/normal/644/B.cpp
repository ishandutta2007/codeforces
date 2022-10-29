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

int n, maxsize;
const int N = 288 * 1000 + 5;
int t[N], d[N];

inline bool read() {
	cin >> n >> maxsize;
	forn(i, n)
		cin >> t[i] >> d[i];
	return true;
}

li ans[N];
queue<int> q;

void solve() {
	
	maxsize++;
	int qsz = 0;
	set<pair<li, int> > ev;

	forn(i, n)
		ev.insert(mp(t[i], i));

	while (!ev.empty()) {
		li curt = ev.begin()->first;
		int id = ev.begin()->second;
		ev.erase(ev.begin());
		if (id < 0) {
			ans[-id - 1] = curt;
			q.pop();
			if (!q.empty()) {
				int next = q.front();
				ev.insert(mp(curt + d[next], -(next + 1)));
			}
		}
		else {
			if (sz(q) == maxsize)
				ans[id] = -1;
			else {
				q.push(id);
				if (sz(q) == 1)
					ev.insert(mp(curt + d[id], -(id + 1)));
			}
		}
	}
	forn(i, n)
		cout << ans[i] << ' ';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif

	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;

	srand(time(NULL));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}