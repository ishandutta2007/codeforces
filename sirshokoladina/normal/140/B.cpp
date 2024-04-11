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

int a[400][400], b[400];

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	int n, x;
	cin >> n;
	forn (i, n) {
		forn (j, n) {
			cin >> x;
			a[i][x - 1] = j;
		}
	}
	forn (i, n) {
		cin >> x;
		b[x - 1] = i;
	}
	forn (i, n) {
		int ans = 0, res = 1000;
		forn (j, n) {
			if (i == 0 && j == 0) {
				continue;
			}
			int best = (i == 0);
			forn (k, j + 1) {
				if (k != i && b[k] < b[best]) {
					best = k;
				}
			}
			if (a[i][best] < res) {
				res = a[i][best];
				ans = j;
			}
		}
		cout << ans + 1 << ' ';
	}
	return 0;
}