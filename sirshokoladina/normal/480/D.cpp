#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(a) int(a.size())

typedef vector<int> vi;

const int N = 501;
const int S = 1000;
const int X = 1000;

int n;
int l[N], r[N], w[N], s[N], v[N];

int num1[N];

int d[N][S + 1];
int q[N + 1];

inline void umx (int &a, int b) {
	if (a < b) {
		a = b;
	}
}

int main () {
	#ifdef SG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	while (cin >> n) {
		scanf("%d", &s[n]);
		forn (i, n) {
			scanf("%d%d%d%d%d", &l[i], &r[i], &w[i], &s[i], &v[i]);
		}
		l[n] = 0;
		r[n] = X;
		w[n] = 0;
		v[n] = 0;
		++n;
		forn (i, n) {
			num1[i] = i;
		}
		sort(num1, num1 + n, [&] (int i, int j) {
			if (r[i] - l[i] != r[j] - l[j]) {
				return r[i] - l[i] > r[j] - l[j];
			}
			if (l[i] != l[j]) {
				return l[i] < l[j];
			}
			if (min(s[i], s[j] - w[i]) != min(s[j], s[i] - w[j])) {
				return min(s[i], s[j] - w[i]) < min(s[j], s[i] - w[j]);
			}
			return false;
		});
		memset(d, 0, sizeof d);
		//cerr << "!!!" << endl;
		ford (ii, n) {
			//cerr << "!!!" << ii << endl;
			int i = num1[ii];
			vi num2;
			for (int jj = ii + 1; jj < n; ++jj) {
				int j = num1[jj];
				if (l[j] >= l[i] && r[j] <= r[i]) {
					num2.pb(j);
				}
			}
			sort(num2.begin(), num2.end(), [&] (int i, int j) {
				return l[i] < l[j];
			});
			vi rs(sz(num2));
			forn (j, sz(num2)) {
				rs[j] = l[num2[j]];
			}
			vi to(sz(num2));
			forn (j, sz(num2)) {
				to[j] = lower_bound(rs.begin(), rs.end(), r[num2[j]]) - rs.begin();
			}
			/*
			cerr << endl;
			cerr << i << endl;
			forn (j, sz(num2)) {
				cerr << num2[j] << ' ';
			}
			cerr << endl;
			forn (j, sz(num2)) {
				cerr << rs[j] << ' ';
			}
			cerr << endl;
			forn (j, sz(num2)) {
				cerr << to[j] << ' ';
			}
			cerr << endl;
			*/
			for (int t = w[i]; t <= S; ++t) {
				int r = min(t - w[i], s[i]);
				memset(q, 0, sizeof q);
				forn (j, sz(num2)) {
					umx(q[j + 1], q[j]);
					umx(q[to[j]], q[j] + d[num2[j]][r]);
				}
				d[i][t] = v[i] + q[sz(num2)];
			}
		}
		cout << d[n - 1][S] << endl;
	}
	
	return 0;
}