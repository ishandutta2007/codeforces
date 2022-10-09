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
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;

vector<int64> a, b, x;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	a.resize(m);
	b.resize(m);
	x.resize(m);
	forn (i, m) {
		cin >> a[i] >> b[i] >> x[i];
	}
	int64 ans = 0;
	forn (i, k) {
		int64 cur;
		cin >> cur;
		forn (j, m) {
			if (a[j] <= cur && cur <= b[j]) {
				ans += x[j] + cur - a[j];
			}
		}
	}
	cout << ans;
}