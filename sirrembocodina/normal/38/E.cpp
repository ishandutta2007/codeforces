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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int int64;

vector<int64> d, s;
vector<pair<int64, int64> > a;

int main() {
	int n;
	cin >> n;
	a.resize(n);
	forn (i, n) {
		cin >> a[i].fs >> a[i].sc;
	}
	sort(a.begin(), a.end());
	s.pb(0);
	forn (i, n - 1) {
		s.pb(s[s.size() - 1] + a[i + 1].fs - a[0].fs);
	}
//	forn (i, s.size()) {
//		cout << s[i] << " ";
//	}
//	cout << endl;
	d.pb(a[0].sc);
	for (int i = 1; i < n; i++) {
		d.pb(a[i].sc + d[0] + s[i - 1]);
		for (int j = 1; j < i; j++) {
			d[i] = min(d[i], a[i].sc + d[j] + s[i - 1] - s[j] - (a[j].fs - a[0].fs) * (i - j - 1));
		}
	}
//	forn (i, d.size()) {
//		cout << d[i] << " ";
//	}
//	cout << endl;
	int64 ans = d[0] + s[n - 1];
	for (int i = 1; i < n; i++) {
		ans = min(ans, d[i] + s[n - 1] - s[i] - (a[i].fs - a[0].fs) * (n - 1 - i));
	}
	cout << ans;
}