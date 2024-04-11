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

long long mod = 1000000007;

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n, m, k;
	cin >> n >> m >> k;
	if (k == n) {
		long long ans = 1;
		forn (i, (k + 1) / 2) {
			ans *= m;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}
	if (k == 1 || k > n) {
		long long ans = 1;
		forn (i, n) {
			ans *= m;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}
	if (k & 1) {
		cout << m * m << endl;
		return 0;
	}
	cout << m << endl;
	return 0;
}