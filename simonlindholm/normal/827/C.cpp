#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ll int
struct FT {
	vector<ll> s;
	void init(int n) {
		s.resize(n);
	}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int ctoi(char c) {
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'G') return 2;
	if (c == 'C') return 3;
	abort();
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	string str;
	cin >> str;
	int N = sz(str);
	FT tr[4][11][10];
	rep(x,0,4) rep(d,1,11) rep(k,0,d) tr[x][d][k].init(N / d + 10);
	rep(i,0,N) {
		char c = str[i];
		int x = ctoi(c);
		rep(d,1,11) {
			tr[x][d][i % d].update(i / d, 1);
		}
	}

	int Q;
	cin >> Q;
	rep(qi,0,Q) {
		int type;
		cin >> type;
		if (type == 1) {
			int i;
			char c;
			cin >> i >> c;
			int x = ctoi(c);
			--i;
			int y = ctoi(str[i]);
			str[i] = c;
			rep(d,1,11) {
				tr[y][d][i % d].update(i / d, -1);
				tr[x][d][i % d].update(i / d, 1);
			}
		} else {
			assert(type == 2);
			int l, r;
			string e;
			cin >> l >> r >> e;
			--l;
			int d = sz(e);
			int res = 0;
			rep(k,0,d) {
				int ind = (k - l) % d;
				if (ind < 0) ind += d;
				int x = ctoi(e[ind]);
				// cerr << "query " << x << ' ' << d << ' ' << k << ' ';
				// cerr << (r - k + d-1)/d << ' ' << (l - k + d-1)/d << endl;
				int re = tr[x][d][k].query((r - k + d-1) / d) - tr[x][d][k].query((l - k + d-1) / d);
				res += re;
			}
			cout << res << '\n';
		}
	}

	exit(0);
}