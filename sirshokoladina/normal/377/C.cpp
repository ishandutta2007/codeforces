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

int n;

int s[110], c[110], p[110];

int k[1 << 20], ans[1 << 20];

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n;
	forn (i, n) {
		cin >> s[i];
	}
	sort(s, s + n);
	reverse(s, s + n);
	{
		int m;
		cin >> m;
		n = m;
	}
	forn (i, n) {
		char c1;
		int p1;
		cin >> c1 >> p1;
		c[i] = (c1 == 'p');
		p[i] = (p1 == 2);
	}
	k[0] = 0;
	forn (i, 1 << n) {
		k[i] = (i & 1) + k[i >> 1];
	}
	
	forn (i, 1 << n) {
		if (!i) {
			ans[i] = 0;
			continue;
		}
		int num = n - k[i];
		if (p[num] == 0) {
			ans[i] = -1000000000;
		} else {
			ans[i] = 1000000000;
		}
		forn (j, n) {
			if (i & (1 << j)) {
				int cur = ans[i - (1 << j)];
				if (c[num] == 1) {
					if (p[num] == 0) {
						cur += s[j];
					} else {
						cur -= s[j];
					}
				}
				if (p[num] == 0) {
					ans[i] = max(ans[i], cur);
				} else {
					ans[i] = min(ans[i], cur);
				}
			}
		}
	}
	cout << ans[(1 << n) - 1] << endl;
	return 0;
}