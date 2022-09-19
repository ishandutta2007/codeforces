#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define forin(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define elif else if
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define last(a) (*(a).end())
#define fill_zero(a) memset(a, 0, sizeof(a))
#define y1 botva
#define count botven
#define norm(a) a.erase(unique(all(a)), a.end());

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;

int x[8], y[8];

int str(int i, int j, int k) {
	return (x[i] - x[j]) * (x[j] - x[k]) + (y[i] - y[j]) * (y[j] - y[k]);
}

int len(int i, int j) {
	return str(i, j, i);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	forn (i, 8) {
		cin >> x[i] >> y[i];
	}
	int a[8];
	forn (i, 8) {
		a[i] = i;
	}
	do {
		bool ok = 1;
		forn (i, 4) {
			ok &= (str(a[i], a[(i + 1) % 4], a[(i + 2) % 4]) == 0);
			ok &= (str(a[i + 4], a[(i + 1) % 4 + 4], a[(i + 2) % 4 + 4]) == 0);
			ok &= (len(a[i], a[(i + 1) % 4]) == len(a[(i + 1) % 4], a[(i + 2) % 4]));
		}
		if (ok) {
			cout << "YES\n";
			forn (i, 8) {
				cout << a[i] + 1 << ' ';
				if (i == 3) {
					cout << endl;
				}
			}
			return 0;
		}
	} while (next_permutation(a, a + 8));
	cout << "NO\n";
	return 0;
}