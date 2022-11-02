#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 11;
const int Mod = (int)1e9 + 7;
using ll = long long;

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

int p[N], v[N];
int find(int x) {
	if(p[x] == x) return x;
	int r = find(p[x]);
	v[x] ^= v[p[x]];
	return p[x] = r;
}

int main() {
	ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	iota(p, p + n + 3, 0);
	int rank = 0;
	while(k --) {
		int x, y; char c;
		cin >> x >> y >> c;
		int t = (c == 'o');
		int l = abs(x - y) + 1;
		int r = ((x + y <= n) ? x + y - 1 : 2 * n - x - y + 1) + 2;

		int pl = find(l), pr = find(r);
		if(pl == pr) {
			if(v[l] ^ v[r] != t) {
				cout << "0\n";
				return 0;
			}
		} else {
			p[pl] = r;
			v[pl] = v[l] ^ t;
			rank ++;
		}
	}

	cout << qpow(2, n - rank) << '\n';
	return 0;
}