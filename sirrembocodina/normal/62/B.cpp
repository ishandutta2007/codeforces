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

string s, t;
vector<vector<int> > a;

int main() {
	int n, k;
	cin >> n >> k;
	cin >> s;
	a.resize(26);
	forv (i, a) {
		a[i].assign(maxN, INF);
	}
	forn (c, 26) {
		int d = INF;
		forn (i, maxN) {
			d++;
			if (i < k && s[i] == (c + 'a')) {
				d = 0;
			}
			a[c][i] = min(a[c][i], d);
		}
		d = INF;
		ford (i, k) {
			d++;
			if (s[i] == (c + 'a')) {
				d = 0;
			}
			a[c][i] = min(a[c][i], d);
		}
	}
	forn (i, n) {
		cin >> t;
		int64 cur = 0;
		forv (i, t) {
			if (a[t[i] - 'a'][i] < INF) {
				cur += int64(a[t[i] - 'a'][i]);
			} else {
				cur += int64(t.size());
			}
		}
		cout << cur << endl;
	}
}