#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define eps 0.000000005

typedef long long int64;       
typedef long double ld;

vector<int> a;
int n;
ld k;

bool can(ld x) {
	ld s1 = 0, s2 = 0;
	forn (i, n) {
		if (a[i] > x) {
			s2 += a[i] - x;
		} else {
			s1 += x - a[i];
		}
	}
//	cout << s1 <<" " << s2 << endl;
	return s1 / s2 <= k;
}

int main() {
	cout.precision(10);
	cin >> n >> k;
	a.resize(n);
	k = 100 - k;
	k /= 100;
	ld l = 0, r = 0;
	forn (i, n) {
		cin >> a[i];
		r = max(ld(a[i]), r);
	}
	while (r - l > eps) {
		ld m = (l + r) / 2;
		if (can(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l;
}