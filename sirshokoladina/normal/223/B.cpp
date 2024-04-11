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

const ld PI = 3.141592653589793238462643l;

void make(string &a, string &b, int *t) {
	int j = 0;
	forn (i, a.size()) {
		if (j < b.size() && a[i] == b[j]) {
			j++;
		}
		t[i] = j;
	}
}
int c[200010][26];

int calc(int l, int r, char a) {
	return c[r][a - 'a'] - c[l][a - 'a'];
}

int l[200010], r[200010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	memset(c, 0, sizeof c);
	forn (i, b.size()) {
		forn (j, 26) {
			c[i + 1][j] = c[i][j];
		}
		c[i + 1][b[i] - 'a']++;
	}
	make(a, b, l);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	make(a, b, r);
	reverse(r, r + a.size());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	forn (i, a.size()) {
//		cerr << b.size() - r[i] << ' ' << l[i] << ' ' << a[i] << ' ' << calc(b.size() - r[i], l[i], a[i]) << endl;
		if (calc(b.size() - r[i], l[i], a[i]) <= 0) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}