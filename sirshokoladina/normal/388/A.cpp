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

int a[100];
int b[100];
int c[100];
int n;

bool can () {
	memcpy(c, b, sizeof b);
	sort(c, c + n);
	forn (i, n) {
		if (a[i] < c[i]) {
			return 0;
		}
	}
	return 1;
}

int main () {
#ifdef SG
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n;
	forn (i, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	int k = 1, l = 0;
	memset(b, 0, sizeof b);
	forn (i, n) {
		b[i] = l;
		if (!can()) {
			k++;
			l = 0;
			b[i] = l;
		}
		l++;
	}
	cout << k << endl;
	return 0;
}