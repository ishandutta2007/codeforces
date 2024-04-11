#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e4 + 11;
const int M = 33;
using pii = pair <int, int>;
using vpii = vector <pii>;

#define pb push_back
#define fi first
#define se second

int x[N], y[N];
int lb(int x) { return x & (-x); }

int y_comb[M];

vpii gauss(int x[], int n, int &b) {
	vpii ret;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < b; j ++)
			if(lb(x[j]) & x[i]) {
				x[i] ^= x[j];
				ret.pb({i, j});
			}
		if(x[i]) {
			for(int j = 0; j < b; j ++)
				if(lb(x[i]) & x[j]) {
					x[j] ^= x[i];
					ret.pb({j, i});
				}
			if(i != b) {
				swap(x[i], x[b]);
				ret.pb({i, b});
				ret.pb({b, i});
				ret.pb({i, b});
			}
			b ++;
		}
	}
	return ret;
}

int p[M];

int cx[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) { cin >> x[i]; cx[i] = x[i]; }
	for(int i = 0; i < n; i ++) cin >> y[i];
	int xb = 0, yb = 0;
	vpii p1 = gauss(x, n, xb);
	vpii p3 = gauss(y, n, yb);

	bool f = true;
	for(int i = 0; i < yb; i ++) {
		for(int j = 0; j < xb; j ++)
			if(lb(x[j]) & y[i]) {
				y[i] ^= x[j];
				y_comb[i] |= (1 << j);
			}
		if(y[i]) f = false;
	}
	if(!f) {
		cout << "-1\n";
		return 0;
	}

	for(int i = 0; i < yb; i ++) {
		for(int j = 0; j < i; j ++)
			if(lb(y_comb[j]) & y_comb[i]) {
				y_comb[i] ^= y_comb[j];
				p3.pb({i, j});
			}
		for(int j = 0; j < i; j ++)
			if(lb(y_comb[i]) & y_comb[j]) {
				y_comb[j] ^= y_comb[i];
				p3.pb({j, i});
			}
	}
	reverse(p3.begin(), p3.end());

	vpii p2;
	iota(p, p + xb, 0);
	for(int i = 0; i < yb; i ++) {
		int now = y_comb[i];
		for(int j = 0; j < i; j ++)
			if((now >> p[j]) & 1) {
				now ^= y_comb[j];
				p2.pb({i, j});
			}
		int l = __builtin_ctz(now);
		if(p[i] != l) {
			int t = -1;
			for(int j = i + 1; j < xb; j ++)
				if(p[j] == l) t = j;
			swap(p[i], p[t]);
			p2.pb({i, t});
			p2.pb({t, i});
			p2.pb({i, t});
		}
		for(int j = i + 1; j < xb; j ++)
			if((now >> p[j]) & 1) {
				p2.pb({i, j});
				now ^= (1 << p[j]);
			}
	}
	for(int i = yb; i < xb; i ++)
		p2.pb({i, i});

	cout << p1.size() + p2.size() + p3.size() << '\n';
	for(vpii v : {p1, p2, p3}) {
		for(pii p : v)
			cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
		//cout << '\n';
	}

	/*
	auto check = [&](vpii v) {
		for(pii p : v)
			cx[p.fi] ^= cx[p.se];
	};
	check(p1); check(p2); check(p3);

	for(int i = 0; i < n; i ++)
		cout << cx[i] << ' ';
	cout << '\n';
	*/

	return 0;
}