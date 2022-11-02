#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 33;

int lowbit(int x) { return x & (-x); }
struct BIT {
	int b[N]; int d;
	void clear(int _d) {
		memset(b, 0, sizeof b);
		d = _d;
	}
	void change(int p, int c) {
		p += d;
		for(int i = p; i < N; i = i % d + (i / d + lowbit(i / d)) * d) {
			//cout << i << ' ' << d << '\n';
			b[i] += c;
		}
	}
	int query(int p) {
		p += d;
		int r = 0;
		for(int i = p; i >= d; i = i % d + (i / d - lowbit(i / d)) * d)
			r += b[i];
		return r;
	}
}bit[11][4];

int f(char i) {
	if(i == 'A') return 0;
	if(i == 'C') return 1;
	if(i == 'G') return 2;
	return 3;
}
int g(int i, int d, int n) {
	if(i > n) return i - d;
	return i + (n - i) / d * d;
}

int main() {
	ios :: sync_with_stdio(0);
	string s; cin >> s; s = '0' + s;
	int n = s.size();
	for(int i = 1; i <= 10; i ++) {
		for(int j = 0; j < 4; j ++)
			bit[i][j].clear(i);
		for(int j = 1; j <= n; j ++)
			bit[i][f(s[j])].change(j, 1);
	}
	
	int m; cin >> m;
	while(m --) {
		int t; cin >> t;
		if(t == 1) {
			int p; char c; cin >> p >> c;
			for(int i = 1; i <= 10; i ++)
				bit[i][f(s[p])].change(p, -1);
			s[p] = c;
			for(int i = 1; i <= 10; i ++)
				bit[i][f(s[p])].change(p, 1);
		} else {
			int l, r; string e;
			cin >> l >> r >> e;
			int se = (l - 1) % e.size();
			rotate(e.begin(), e.end() - se, e.end());
			e = '0' + e;
			//cout << e << '\n';
			int ans = 0;
			for(int i = 1; i <= e.size() - 1; i ++) {
				//cout << i << ' ' << g(i, e.size() - 1, r) << ' ' << g(i, e.size() - 1, l - 1) << '\n';
				ans += bit[e.size() - 1][f(e[i])].query(g(i, e.size() - 1, r));
				ans -= bit[e.size() - 1][f(e[i])].query(g(i, e.size() - 1, l - 1));
			}
			cout << ans << '\n';
		}
	}
	
}