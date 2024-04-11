#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long int64;

int a[100100], b[100100], w[100100];
bool c[100100];

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		a[i] = b[i] = 0;
	}
	int mn = 0;
	forn (i, n) {
		int x;
		cin >> x;
		w[i] = x;
		if (x > 0) {
			x--;
			a[x]++;
		} else {
			x = -x;
			x--;
			mn++;
			b[x]++;
		}
	}
	int k = 0;
	forn (i, n) {
		c[i] = a[i] + mn - b[i] == m;
		k += c[i];
	}
	forn (i, n) {
		if (w[i] > 0) {
			w[i]--;
			if (!c[w[i]]) {
				cout << "Lie\n";
			} else if (k > 1) {
				cout << "Not defined\n";
			} else {
				cout << "Truth\n";
			}
		} else {
			w[i] = -w[i];
			w[i]--;
			if (!c[w[i]]) {
				cout << "Truth\n";
			} else if (k > 1) {
				cout << "Not defined\n";
			} else {
				cout << "Lie\n";
			}
		}
	}
}