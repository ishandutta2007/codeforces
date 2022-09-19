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

const int N = 1 << 19;

int t[2 * N], u[2 * N];
int lb[2 * N], rb[2 * N];

void upd (int l, int r, int d, int v = 0) {
	if (l >= rb[v] || r <= lb[v]) {
		return;
	}
	if (l <= lb[v] && r >= rb[v]) {
		u[v] += d;
		return;
	}
	u[2 * v + 1] += u[v];
	u[2 * v + 2] += u[v];
	u[v] = 0;
	upd(l, r, d, 2 * v + 1);
	upd(l, r, d, 2 * v + 2);
	t[v] = max(t[2 * v + 1] + u[2 * v + 1], t[2 * v + 2] + u[2 * v + 2]);
}

int l[N], v[N], r[N];
vector<int> l_[N], v_[N];

int main () {
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	memset(t, 0, sizeof t);
	memset(u, 0, sizeof u);
	forn (i, N) {
		lb[N - 1 + i] = i;
		rb[N - 1 + i] = i + 1;
	}
	ford (i, N - 1) {
		lb[i] = lb[2 * i + 1];
		rb[i] = rb[2 * i + 2];
	}
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d%d%d", &l[i], &v[i], &r[i]);
		l_[l[i]].pb(i);
		v_[v[i]].pb(i);
		r[i]++;
	}

	int ans = 0;
	int ansl = 0, ansr = 0;
	ford (i, N) {
		forn (j, v_[i].size()) {
			upd(i, r[v_[i][j]], 1);
		}

		int cur = t[0] + u[0];
		if (cur > ans) {
			ans = cur;
			ansl = i;
			int v = 0;
			while (v < N - 1) {
				u[2 * v + 1] += u[v];
				u[2 * v + 2] += u[v];
				t[v] += u[v];
				u[v] = 0;
				v = 2 * v + 2;
				if (t[v] + u[v] < cur) {
					--v;
				}
			}
			ansr = v - N + 1;
		}

		forn (j, l_[i].size()) {
			upd(v[l_[i][j]], r[l_[i][j]], -1);
		}
	}

	cout << ans << endl;
//	cerr << ansl << ' ' << ansr << endl;
	forn (i, n) {
		if (l[i] <= ansl && r[i] > ansr && v[i] >= ansl && v[i] <= ansr) {
			printf("%d ", i + 1);
		}
	}
	puts("");
	return 0;
}