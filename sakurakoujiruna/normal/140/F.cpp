#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;
#define op operator

struct poi {
	int x, y;
	void r() { cin >> x >> y; }
	poi op -(poi p) {
		return {x - p.x, y - p.y};
	}
	poi op +(poi p) {
		return {x + p.x, y + p.y};
	}
	bool op <(poi p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	bool op ==(poi p) {
		return tie(x, y) == tie(p.x, p.y);
	}
}p[N];

int main() {
	cout << fixed << setprecision(1);
	ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	if(k >= n) {
		cout << -1 << '\n';
		return 0;
	}
	for(int i = 0; i < n; i ++)
		p[i].r();
	sort(p, p + n);

	auto check = [&](poi m) {
		int cnt = 0, t = 0;
		for(int i = n - 1; i >= 0; i --) {
			while(t < n && p[t] < m - p[i])
				t ++;
			if(t == n || !(p[t] == m - p[i]))
				cnt ++;
		}
		return cnt <= k;
	};

	set <poi> ans;
	for(int i = 1; i <= k + 1; i ++)
		for(int j = 1; i + j <= k + 2; j ++) {
			poi m = p[i - 1] + p[n - j];
			if(check(m))
				ans.insert(m);
		}

	cout << ans.size() << '\n';
	for(auto p : ans)
		cout << p.x / 2.0L << ' ' << p.y / 2.0L << '\n';
	return 0;
}