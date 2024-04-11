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

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

vector<int> e[2010];
int l[2010];
bool u[2010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	getline(cin, s);
	forn (i, n) {
		getline(cin, s);
		forn (j, m) {
			if (s[j] == '#') {
				int x = i;
				int y = j + 1005;
				e[x].pb(y);
				e[y].pb(x);
			}
		}
	}
	forn (i, 2010) {
		u[i] = 0;
		l[i] = -1;
	}
	vector<int> q(1, 0);
	l[0] = 0;
	u[0] = 1;
	forn (i, q.size()) {
		forn (j, e[q[i]].size()) {
			if (!u[e[q[i]][j]]) {
				q.pb(e[q[i]][j]);
				l[e[q[i]][j]] = l[q[i]] + 1;
				u[e[q[i]][j]] = 1;
			}
		}
	}
	cout << l[n - 1];
	return 0;
}