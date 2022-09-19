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

bool p[10000010];
int a[10000010];

int m = 3200;

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	memset(p, -1, sizeof p);
	p[0] = p[1] = 0;
	forn (i, m) {
		if (p[i]) {
			for (int j = i * i; j < m; j += i) {
				p[j] = 0;
			}
		}
	}
	forn (i, 10000010) {
		a[i] = i;
	}
	forn (i, m) {
		if (p[i]) {
			int I = i * i;
			for (int j = I; j < 10000010; j += I) {
				while (a[j] % I == 0) {
					a[j] /= I;
				}
			}
		}
	}
	int q, n;
	cin >> q >> n;
	ll ans = 0;
	forn (i, n) {
		ans += a[q + i];
	}
	cout << ans;
	return 0;
}