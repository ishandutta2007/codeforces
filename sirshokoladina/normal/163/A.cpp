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
typedef int ll;//
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

const ll mod = 1000000007;

string s, t;

ll a[2][10000];

void qwe(ll &a) {
	if (a >= mod) {
		a -= mod;
	}
}

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	getline(cin, s);
	getline(cin, t);
	memset(a, 0, sizeof a);
	int n = s.size();
	int m = t.size();
	ll ans = 0;
	forn (i, n) {
		ll su = 0;
		forn (j, m) {
			if (t[j] == s[i]) {
				su += 1;
				if (j) {
					su += a[(i & 1) ^ 1][j - 1];
				}
				qwe(su);
			}
			a[i & 1][j] = su;
			//cerr << a[i & 1][j] << ' ';
		}
		//cerr << endl;
		ans += su;
		qwe(ans);
	}
	cout << ans;
	return 0;
}