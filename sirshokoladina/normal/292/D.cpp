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

int n, m;
int x[10010], y[10010];

int p[510];

int getp (int i) {
	if (p[i] == i) {
		return i;
	}
	return p[i] = getp(p[i]);
}

int qwe = 0;

int uni (int i, int j) {
	i = getp(i);
	j = getp(j);
	if (i == j) {
		return 0;
	}
	if (qwe ^= 1) {
		p[i] = j;
	} else {
		p[j] = i;
	}
	return 1;
}

void clean () {
	forn (i, n) {
		p[i] = i;
	}
}

int tuda[510], suda[510];
int ts = 0, ss = 0;

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n >> m;
	forn (i, m) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}
	clean();
	forn (i, m) {
		if (uni(x[i], y[i])) {
			tuda[ts++] = i;
		}
	}
	clean();
	ford (i, m) {
		if (uni(x[i], y[i])) {
			suda[ss++] = i;
		}
	}
	int k;
	cin >> k;
	forn (i, k) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		clean();
		int cnt = 0;
		for (int i = 0; i < ts && tuda[i] < l; ++i) {
			cnt += uni(x[tuda[i]], y[tuda[i]]);
		}
		for (int i = 0; i < ss && suda[i] > r; ++i) {
			cnt += uni(x[suda[i]], y[suda[i]]);
		}
		cout << n - cnt << endl;
	}
	return 0;
}