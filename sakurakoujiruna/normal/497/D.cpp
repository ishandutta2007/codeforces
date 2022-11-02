#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

#define op operator

const int N = 1e3L + 11;

struct poi {
	ll x, y;
	void r() { cin >> x >> y; }
	poi op -(poi p) {
		return {x - p.x, y - p.y};
	}
	ll dot(poi p) {
		return x * p.x + y * p.y;
	}
	ll cross(poi p) {
		return x * p.y - y * p.x;
	}
	ll len2() { return dot(*this); }
}p[N], q[N];

bool check(poi a, poi b, poi o, ll r2) {
	a = a - o; b = b - o; o = {0, 0};
	if(a.len2() <= r2 && b.len2() >= r2 ||
		a.len2() >= r2 && b.len2() <= r2) return 1;
	if(a.len2() < r2 && b.len2() < r2) return 0;
	if(a.cross(b) * a.cross(b) > r2 * (b - a).len2()) return 0;
	if(a.dot(a - b) > 0 && b.dot(b - a) > 0) return 1;
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	poi a; a.r();
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		p[i].r();
	p[n] = p[0];
	poi b; b.r();
	int m; cin >> m;
	for(int i = 0; i < m; i ++)
		q[i].r();
	q[m] = q[0];
	
	if(a.x == b.x && a.y == b.y) {
		cout << "NO\n";
		return 0;
	}
	
	bool f = 0;
	for(int _ : {0, 1}) {
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(check(p[i] - a, p[i + 1] - a, q[j] - b, (b - a).len2())) {
					f = 1;
					//cout << _ << ' ' << i << ' ' << j << '\n';
				}
		
		swap(n, m); swap(a, b);
		for(int i = 0; i < N; i ++)
			swap(p[i], q[i]);
	}
	
	cout << (f ? "YES" : "NO") << '\n';
	
	return 0;
}