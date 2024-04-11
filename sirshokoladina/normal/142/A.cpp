#pragma comment(linker, "/STACK:32000000")
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

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	ll n;
	cin >> n;
	ll ans1 = 1000000000000000l, ans2 = 0;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i) {
			continue;
		}
		ll a = i;
		ll b = n / i;
		forn (i, 2) {
			for (ll j = 1; j * j <= a; j++) {
				if (a % j) {
					continue;
				}
				ll c = a / j;
				ll k = (b + 1) * (j + 2) * (c + 2) - b * j * c;
				ans1 = min(ans1, k);
				ans2 = max(ans2, k);
			}
			swap(a, b);
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}