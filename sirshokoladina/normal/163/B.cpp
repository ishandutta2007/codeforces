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

int K, n;
pair<pair<int, int>, int> a[100010];
ld v[100010];

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)

	int heriu;
	cin >> n >> K >> heriu;
	forn (i, n) {
		a[i].sc = i;
		cin >> a[i].fs.fs;
	}
	forn (i, n) {
		cin >> a[i].fs.sc;
	}
	sort(a, a + n);
	forn (i, n) {
		v[i] = a[i].fs.sc;
	}
	ld l = 0, r = 100000.1;
	int x = 100;
	forn (wegy, x) {
		ld m = (l + r) / 2;
		int k = 0;
		forn (i, n) {
			if ((k + 1) < m * v[i]) {
				k++;
			}
		}
		if (k < K) {
			l = m;
		} else {
			r = m;
		}
	}
//	printf("%0.2lf\n", double(r));
	int k = 0;
	forn (i, n) {
		if ((k + 1) < r * v[i]) {
			k++;
			if (k <= K) {
				cout << a[i].sc + 1 << ' ';
			}
		}
	}
	return 0;
}