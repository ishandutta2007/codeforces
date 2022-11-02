#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
#include <cassert>
#include <complex>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i ++)
#define ford(i,n) for (int j = (int)(n)-1; j >= 0; j --)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define I (int)
#define seta(x,y) memset (x, y, sizeof (x))

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const int inf = (1 << 30) - 1;
const int64 inf64 = (1LL << 62) - 1;
const ldb eps = 1e-9;
const ldb pi = acosl(-1.); 

int n;
bool used[5100];
int s[5100];
vector<int> g[5100];

void go(int v, int p) {
    if (used[v])
        return;
    used[v] = 1;
    s[v] = 1;
	forn(i, g[v].size()) {
		if (g[v][i] == p)
			continue;
		go(g[v][i], v);
		s[v] += s[g[v][i]];
	} 
}

bool ans[5101];
bool t[5100][5100];
vector <int> q;

void calc (int v) {
	q.clear ();
	forn(i, g[v].size())
		if (s[g[v][i]] < s[v])
			q.pb(s[g[v][i]]);
		else
			q.pb(n-s[v]);
	int m = q.size();
	forn(i, m+1)
		forn(j, n+1)
			t[i][j] = 0;
	t[0][0] = 1;
	forn(i, m)
		forn(j, n+1)
			if (t[i][j]) {
				t[i+1][j] = 1;
				t[i+1][j+q[i]] = 1;
			}
	forn(j, n+1)
		ans[j] |= t[m][j];
}

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
	cin >> n;
	forn (i, n-1) {
		int x, y;
		cin >> x >> y;
		x --;
		y --;
		g[x].pb (y);
		g[y].pb (x);
	}
	seta(used, 0);
	go(0, -1);
	seta(ans, 0);
	forn(i, n)
		if (g[i].size() > 1) {
			calc(i);
		}
	vector<pii> a;
	forn(i, n)
		if (i > 0 && n-1-i > 0 && ans[i])
			a.pb(mp(i, n-1-i));
	printf("%d\n", a.size());
	forn(i, a.size())
		printf("%d %d\n", a[i].fs, a[i].sc);
	return 0;
}