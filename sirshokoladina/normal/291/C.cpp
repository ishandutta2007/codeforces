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

ui q[100100];

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, k;
	cin >> n >> k;
	forn (i, n) {
		ui a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		q[i] = d + 256u * (c + 256u * (b + 256u * a));
	}
	sort(q, q + n);
	for (int i = 31; i > 0; --i) {
		ui msk = 0u - (1u << i);
		int ans = 0;
		forn (j, n) {
			if (j == 0 || (q[j - 1] & msk) != (q[j] & msk)) {
				ans++;
			}
		}
		if (ans == k) {
			ui d = msk % 256;
			msk /= 256;
			ui c = msk % 256;
			msk /= 256;
			ui b = msk % 256;
			msk /= 256;
			ui a = msk % 256;
			cout << a << '.' << b << '.' << c << '.' << d << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}