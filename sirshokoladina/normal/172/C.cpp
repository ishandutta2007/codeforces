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

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int t[100010], x[100010];
int ans[100010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		cin >> t[i] >> x[i];
	}
	int l = 0;
	int T = 0;
	forn (qwe, (n + m - 1) / m) {
		int r = min(n, l + m);
		T = max(T, t[r - 1]);
		vector<pair<int, int> > numx;
		for (int i = l; i < r; i++) {
			numx.pb(mp(x[i], i));
		}
		sort(numx.begin(), numx.end());
		int D = 0;
		for (int i = 0; i < numx.size(); ) {
			T += numx[i].fs - D;
			D = numx[i].fs;
			int j = i;
			while (j < numx.size() && numx[j].fs == numx[i].fs) {
				ans[numx[j].sc] = T;
				j++;
			}
			T += 1 + (j - i) / 2;
			i = j;
		}
		T += D;
		l = r;
	}
	forn (i, n) {
		if (i) {
			cout << ' ';
		}
		cout << ans[i];
	}
	cout << endl;
	return 0;
}