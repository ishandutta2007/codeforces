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

const ll n = 360360;
ll k;

ll d[n + 1];

ll calc(ll a, ll b) {
	forn (i, n + 1) {
		if (i < b) {
			d[i] = 100000000;
			continue;
		}
		if (i == b) {
			d[i] = 0;
			continue;
		}
		d[i] = 1 + d[i - 1];
		for (ll t = 2; t <= k; ++t) {
			d[i] = min(d[i], 1 + d[i - i % t]);
		}
	}
	return d[a];
}

int main() {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	ll a, b;
	cin >> a >> b >> k;
	if (a / n == b / n) {
		cout << calc(a % n, b % n) << endl;
	} else {
		cout << (a / n - b / n - 1) * calc(n, 0) + calc(a % n, 0) + calc(n, b % n);
	}
	return 0;
}