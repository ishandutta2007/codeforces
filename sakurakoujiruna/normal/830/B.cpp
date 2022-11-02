#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
const int N = 1e5L + 11;

int lb(int x) { return x & (-x); }
struct bit {
	int b[N];
	void change(int p, int c) {
		p += 4;
		for(; p < N; p += lb(p))
			b[p] += c;
	}
	int query(int p) {
		p += 4;
		int r = 0;
		for(; p; p -= lb(p))
			r += b[p];
		return r;
	}
}bit;

vector <int> v[N];

int n;
int f(int i, int j) {
	if(i <= j) return j - i;
	return j - i + n;
}

int g(int a, int b) {
	if(a <= b) return bit.query(b) - bit.query(a);
	return bit.query(n) - (bit.query(a) - bit.query(b));
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x;
		v[x].pb(i);
	}
	ll ans = 0;
	int last = 0;
	for(int i = 0; i < N; i ++) if(v[i].size()) {
		int k = last;
		for(int j : v[i])
			if(f(last, j) > f(last, k))
				k = j;
		//cout << last << ' ' << k << ' ' << f(last, k) << ' ' << g(last, k) << '\n';
		ans += f(last, k) - g(last, k);
		last = k;
		
		for(int j : v[i])
			bit.change(j, 1);
	}
	cout << ans << '\n';
}