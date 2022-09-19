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

string s[1000010];
int a[1000010];
int ss[1000010];
int nx[1000010][22];

int S (int l, int r) {
	return ss[r] - ss[l] + r - l - 1;
}

int main () {
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, R, C;
	cin >> n >> R >> C;
	ss[0] = 0;
	forn (i, n) {
		cin >> s[i];
		a[i] = s[i].size();
		ss[i + 1] = ss[i] + a[i];
	}
	forn (i, 22) {
		nx[n][i] = n;
	}
	int mx = -1;
	int best_i = -1;
	ford (i, n) {
		int l = i;
		int r = n;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (S(i, m) > C) {
				r = m - 1;
			} else {
				l = m;
			}
		}
		nx[i][0] = l;
		forn (j, 21) {
			nx[i][j + 1] = nx[nx[i][j]][j];
		}
		int t = i;
		forn (j, 22) {
			if (R & (1 << j)) {
				t = nx[t][j];
			}
		}
		if (t - i > mx) {
			mx = t - i;
			best_i = i;
		}
	}
	int cur_c = 0;
	forn (j, mx) {
		if (cur_c + a[best_i + j] > C) {
			cur_c = 0;
			cout << endl;
		}
		if (cur_c) {
			cout << ' ';
		}
		cout << s[best_i + j];
		cur_c += a[best_i + j] + 1;
	}
	return 0;
}