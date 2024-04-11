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

ll mod = 1000000007;

bool q[2000];

int s0[2000], s1[2000];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	string a, b;
	cin >> a >> b;
	int n, k = a.size();
	cin >> n;
	b = b + b;
	forn (i, k) {
		q[i] = !memcmp(a.data(), b.data() + i, k);
	}
	ll x = 1, y = 0;
	forn (i, n) {
		ll x1 = (k - 1) * y % mod;
		ll y1 = ((k - 2) * y + x) % mod;
		x = x1;
		y = y1;
	}
	ll ans = 0;
	forn (i, k) {
		if (q[i]) {
			ans += (i ? y : x);
			ans %= mod;
		}
	}
	cout << ans;
	return 0;
}