#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

string s, t;

int pr[200100], sf[200100], sum[26][200100];

int main() {
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int cur = 0;
	forn (i, n) {
		pr[i] = cur;
		if (cur < m && s[i] == t[cur]) {
			++cur;
		}
	}
	cur = m - 1;
	ford (i, n) {
		sf[i] = cur + 1;
		if (cur >= 0 && s[i] == t[cur]) {
			--cur;
		}
	}
	forn (c, 26) {
		sum[c][0] = 0;
		forn (i, m) {
			sum[c][i + 1] = sum[c][i] + (t[i] == 'a' + c);
		}
	}
	bool ok = true;
	forn (i, n) {
		if (sum[s[i] - 'a'][min(pr[i] + 1, m)] <= sum[s[i] - 'a'][max(sf[i] - 1, 0)]) {
//			cerr << i << " " << pr[i] << " " << sf[i] << endl;
			ok = false;
			break;
		}
	}
	cout << (ok ? "YES" : "NO");
}