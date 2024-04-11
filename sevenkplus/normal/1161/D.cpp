#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 2010
#define P 998244353
string s;
int n, m;
int v[N];
int f[N];
vector<int> c;

bool ff(int x) {
	bool F = true;
	c.pb(x);
	if (x == n + m-1 && v[x] == 0) F = false;
	if (x == n-1 && v[x] == 0) F = false;
	if (x < n && x >= m && s[x] != '?' && v[x] != s[x]-'0') F = false;
	if (x < n) {
		if (v[n-1-x] == -1) {
			v[n-1-x] = v[x];
			F &= ff(n-1-x);
		} else {
			if (v[n-1-x] != v[x]) F = false;
		}
		if (x < m && s[x] != '?') {
			if (v[n+x] == -1) {
				v[n+x] = v[x] ^ (s[x]-'0');
				F &= ff(n+x);
			} else {
				if (v[n+x] != (v[x] ^ (s[x]-'0'))) F = false;
			}
		}
	}
	if (n <= x && x-n < m) {
		int y = n + m-1-(x-n);
		if (v[y] == -1) {
			v[y] = v[x];
			F &= ff(y);
		} else {
			if (v[y] != v[x]) F = false;
		}
		if (s[x-n] != '?') {
			if (v[x-n] == -1) {
				v[x-n] = v[x] ^ (s[x-n]-'0');
				F &= ff(x-n);
			} else {
				if (v[x-n] != (v[x] ^ (s[x-n]-'0'))) F = false;
			}
		}
	}
	return F;
}

int main() {
	cin >> s;
	reverse(s.begin(), s.end());
	n = s.size();
	int S = 0;
	for (m = 1; m < n; m ++) {
		int U = 1;
		memset(v, -1, sizeof v);
		for (int i = 0; i < n+m; i ++)
			if (v[i] == -1) {
				int T = 0;
				c.clear();
				v[i] = 0;
				if (ff(i)) T++;
				for (auto j : c) v[j] = -1;
				c.clear();
				v[i] = 1;
				if (ff(i)) T++;
				U = (ll)U*T%P;
				// for (auto j : c) printf("%d ", j);
				// cout << T << endl;
			}
		// cout << U << endl;
		(S += U) %= P;
	}
	cout << S << endl;
	return 0;
}