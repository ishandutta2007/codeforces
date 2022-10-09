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

typedef long long int64;       
typedef long double ld;

const int INF = 1000000000;
const int maxN = 200010;

int main() {
	int n, k;
	vector<int> a, b;
	cin >> n >> k;
	b.resize(n);
	forn (i, n) {
		cin >> b[i];
	}
	fordab (i, 1, n + 1) {
		vector<int> c;
		c.clear();
		c.pb(0);
		forv (j, a) {
			c.pb(c[j] + (i + k <= a[j]));
		}
		int k = 0;
		forn (j, c.size()) {
			if (c[j] == b[i - 1]) {
				k = j;
				break;
			}
		}
		c.clear();
		int cur = 0;
		forn (j, a.size() + 1) {
			if (j == k) {
				c.pb(i);
			} else {
				c.pb(a[cur]);
				cur++;
			}
		}
		a = c;
//		forn (i, a.size()) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
	}
	forn (i, n) {
		cout << a[i] << " ";
	}
}