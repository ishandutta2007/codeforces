#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

int p[100010];
vector<int> c[100010];
string s[100010];

string t;
int ss[300010], e[300010][26];

int dfs (int v, int k) {
	int ans = 0;
	forn (i, s[v].size()) {
		k = e[k][s[v][i] - 'a'];
		if (k == (int)t.size()) {
			ans++;
		}
	}
	forn (i, c[v].size()) {
		ans += dfs(c[v][i], k);
	}
	return ans;
}

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i] >> s[i];
		p[i]--;
		c[p[i]].pb(i);
	}
	cin >> t;
	memset(ss, 0, sizeof ss);
	memset(e, 0, sizeof e);
	forn (i, t.size()) {
		ss[i + 1] = e[ss[i]][t[i] - 'a'];
		e[i][t[i] - 'a'] = i + 1;
		forn (j, 26) {
			e[i + 1][j] = e[ss[i + 1]][j];
		}
	}
	cout << dfs(0, 0) << endl;
	return 0;
}