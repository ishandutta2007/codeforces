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
	string s;
	cin >> s;
	bool was = false;
	int n = s.size();
	forn (i, n) {
		if (s[i] == '0') {
			if (!was) {
				was = true;
				continue;
			}
		}
		if (i == n - 1 && !was) {
			continue;
		}
		cout << s[i];
	}
	cout << endl;
}