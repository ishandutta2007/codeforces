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

const ll mod = 1000000007ll;

ll d[100];

map<pii, ll> q;

ll calc (int n, int k) {
	if (n < 0) {
		return 0;
	}
	if ((1 << k) > n + 1) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	pii p = mp(n, k);
	if (q.count(p)) {
		return q[p];
	}
	if (n & 1) {
		 q[p] = (
		 	calc(n / 2, k) * d[k] + 
		 	calc(n / 2, k - 1)
		 ) % mod;
	} else {
		 q[p] = (
		 	calc(n / 2 - 1, k) * d[k] + 
		 	(calc(n / 2, k) + mod - calc(n / 2 - 1, k)) * d[k - 1] +
		 	calc(n / 2 - 1, k - 1)
		 ) % mod;
	}
	return q[p];
}

int main () {
#ifdef SG
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	d[0] = 1;
	forn (i, 100) {
		d[i + 1] = d[i] * 2 % mod;
	}
	int n;
	cin >> n;
	ll ans = 0;
	forn (i, 30) {
		(ans += calc(n, i)) %= mod;
	}
	cout << ans << endl;
	return 0;
}