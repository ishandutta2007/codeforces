#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;

vector<int> a, b, c, d;
vector<bool> used;
int n;

bool eq(int a, int b, int c, int d, int x, int y, int z, int t) {
	return a == x && b == y && c == z && d == t;
}

bool eqTurn(int a, int b, int c, int d, int x, int y, int z, int t) {
	vector<int> f;
	f.pb(a);
	f.pb(b);
	f.pb(c);
	f.pb(d);
	bool yes = false;
	forn (i, 4) {
		if (eq(f[i], f[(i + 1) % 4], f[(i + 2) % 4], f[(i + 3) % 4], x, y, z, t)) {
			yes = true;
		}
	}
	return yes;
}

int main() { 
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	d.resize(n);
	forn (i, n) {
		string s;
		cin >> s;
		a[i] = s[0] - '0';
		b[i] = s[1] - '0';
		cin >> s;
		c[i] = s[0] - '0';
		d[i] = s[1] - '0';
		if (i != n - 1) {
			cin >> s;
		}
	}
	int ans = 0;
	used.assign(n, false);
	forn (i, n) {
		if (!used[i]) {
			ans++;
			forab (j, i, n) {
				if (eqTurn(a[i], b[i], d[i], c[i], a[j], b[j], d[j], c[j])) {
					used[j] = true;
				}
			}
		}
	}
	cout << ans;
}