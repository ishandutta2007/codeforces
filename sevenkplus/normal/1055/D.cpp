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

#define INF 1000000007
#define N 3010
int n;
string a[N], b[N];
int lw[N], rw[N];
int f[N];
string s;

int ff(string t) {
	int fa = 0;
	for (int i = 0; i < (int) t.size(); i ++) {
		while (fa && t[i] != s[fa]) fa = f[fa-1];
		if (t[i] == s[fa]) fa++;
		if (fa == (int) s.size()) return i-fa+1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	int nw = 0;
	for (int i = 0; i < n; i ++) {
		int l = INF, r = -INF;
		for (int j = 0; j < (int) a[i].size(); j ++)
			if (a[i][j] != b[i][j]) {
				l = min(l, j);
				r = max(r, j);
			}
		if (l == INF) continue;
		swap(a[i], a[nw]);
		swap(b[i], b[nw]);
		lw[nw] = l;
		rw[nw] = r;
		nw++;
	}
	while (true) {
		bool F = true;
		char ca = '0', cb = '0';
		for (int i = 0; i < nw; i ++) {
			if (lw[i] == 0) {F = false; break;}
			if (ca != '0' && ca != a[i][lw[i]-1]) {F = false; break;}
			if (cb != '0' && cb != b[i][lw[i]-1]) {F = false; break;}
			ca = a[i][lw[i]-1];
			cb = b[i][lw[i]-1];
		}
		if (F) {
			for (int i = 0; i < nw; i ++) lw[i] --;
		} else break;
	}
	
	while (true) {
		bool F = true;
		char ca = '0', cb = '0';
		for (int i = 0; i < nw; i ++) {
			if (rw[i] == (int) a[i].size() -1) {F = false; break;}
			if (ca != '0' && ca != a[i][rw[i]+1]) {F = false; break;}
			if (cb != '0' && cb != b[i][rw[i]+1]) {F = false; break;}
			ca = a[i][rw[i]+1];
			cb = b[i][rw[i]+1];
		}
		if (F) {
			for (int i = 0; i < nw; i ++) rw[i] ++;
		} else break;
	}

	s = a[0].substr(lw[0], rw[0]-lw[0]+1);
	string t = b[0].substr(lw[0], rw[0]-lw[0]+1);

	int fa = 0;
	for (int i = 1; i < (int) s.size(); i ++) {
		while (fa && s[i] != s[fa]) fa = f[fa-1];
		if (s[i] == s[fa]) fa++;
		f[i] = fa;
	}

	bool F = true;
	for (int i = 0; i < nw; i ++)
		if (ff(a[i]) != lw[i]) {
			F = false; break;
		}
	for (int i = nw; i < n; i ++)
		if (ff(a[i]) != -1) {
			F = false; break;
		}
	if (F) {
		cout << "YES" << endl;
		cout << s << endl;
		cout << t << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}