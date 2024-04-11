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

const ld PI = 3.141592653589793238462643l;

int main() {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> q(n), s(n);
	forn (i, n) {
		cin >> q[i];
		q[i]--;
	}
	forn (i, n) {
		cin >> s[i];
		s[i]--;
	}
	vector<int> e(n);
	forn (i, n) {
		e[i] = i;
	}
	int l = 0, r = 0;
	{
		vector<int> p = e;
		while (l < 110) {
			if (p == s) {
				break;
			}
			vector<int> p0 = p;
			forn (i, n) {
				p[i] = p0[q[i]];
			}
			l++;
		}
	}
	{
		vector<int> p = e;
		while (r < 110) {
			if (p == s) {
				break;
			}
			vector<int> p0 = p;
			forn (i, n) {
				p[q[i]] = p0[i];
			}
			r++;
		}
	}
//	cerr << l << ' ' << r << endl;
	if ((l == 0 || r == 0) && k == 0) {
		cout << "YES" << endl;
		return 0;
	}
	if (l == 0 || r == 0 || k == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (l == 1 && r == 1) {
		if (k != 1) {
			cout << "NO" << endl;
			return 0;
		} else {
			cout << "YES" << endl;
			return 0;
		}
	}
	if (l <= k && (l - k) % 2 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	if (r <= k && (r - k) % 2 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}