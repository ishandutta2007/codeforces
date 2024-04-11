#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
//	forn (i, 14) {
//		cerr << char('a' + i);
//	}
	string s, t = "";
	cin >> s;
//	s = 'a' + s;
	int x;
	cin >> x;
	forn (i, s.size()) {
		if (s[i] < 'a') {
			s[i] += 'a' - 'A';
		}
	}
	forn (i, s.size()) {
		if (s[i] < x + 'a') {
			t += 'A' + s[i] - (s[i] < 'a' ? 'A' : 'a');
		} else {
			t += 'a' + s[i] - (s[i] < 'a' ? 'A' : 'a');
		}
	}
	cout << t;
}