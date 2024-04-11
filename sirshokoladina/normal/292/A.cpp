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

int t[1010], c[1010], d[1010];

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	forn (i, n) {
		cin >> t[i] >> c[i];
	}
	int T = 0;
	int mx = 0;
	forn (i, n) {
		if (T < t[i]) {
			T = t[i];
		}
		T += c[i];
		d[i] = T;
		int s = T - t[i];
		if (mx < s) {
			mx = s;
		}
	}
	cout << T << ' ' << mx << endl;
	return 0;
}